# hashing

## 复杂结构的hash

在一些复杂结构中比较往往需要较高的复杂度。在需要高数量级的判断时 , 往往采用hash的技术 , 消耗一定代价进行预处理 , 能使判断的复杂度降为 $\mathcal{O(1)}$ 。  

良好的hash设计应该使碰撞概率极低 , 这样对hash值的比较可以近似认为是对结构相等性的比较。  

好的hash设计应当支持对原结构的操作方便用原hash值计算出结果的hash值。  

在应用中，将一些复杂问题特殊性的判定抽象为复杂基本结构相等性的判定。然后用hashing加速这个过程。对于高频率需要调用判定的情况下 , 预处理出hash值能够很快地完成判定。  

### 集合hash



#### 技巧 : 将复杂性质的判断转化为复杂结构相等性的判断

例题 : CF1394B  



### 图hash

#### 图的同构

对于图 $G_1 = (V_1, E_1)$ , $G_2 = (V_2, E_2)$ , $G_1$ 与 $G_2$ 同构当且仅当 $\exist f: V_1 \xrightarrow{} V_2$ 满足 $a \xrightarrow{} b \in E_1$ 当且仅当 $f(a) \xrightarrow{} f(b) \in E_2$ , 且 $f$ 是一个双射(bijective function)(双射同时保证了 $\left| V_1 \right| = \left| V_2 \right|$ )。非形式化地讲 , 两图同构当且仅当两图节点个数相同 , 存在给节点重编号的方案 , 使得边集也相同。  

#### 树hash

树hash用于快速判断树的同构。观察到同构不与点编号相关而仅与与之相邻的节点相关。加之树的递归结构 , 我们的hash函数也应当以根的各个子树的信息为关键量。  

记 $f_x$ 为以 $x$ 为根的子树的hash值 , 以下hash函数是优秀的 : 
$$
f(x) = 1 + \sum_{y \in son(x)} f(y) \times prime(size(y))
$$
其中 , $prime(x)$ 代表从小到大第 $x$ 个质数 , 这样

对于一棵有根树 , 以这样的方式构造的树的hash是一个数值 , 即根的hash值。对于一棵无根树 , 由于没有办法确定根 , 它的hash是一个集合 , 每个元素代表了以某一个节点为根的hash值。

有根树可以直接采用朴素的树形DP来求解 , 对于无根树 , 直接枚举每一个点为根进行树形DP显然是会T飞的 , 因此考虑换根的思想来求每个点为根时树的hash值 , 避免冗余计算。

令 $x$ 为 $y$ 的父亲 , 我们考虑 $x$ 为根的情况下维护的量与转到 $y$ 为根时维护的量的变化 : 

记 $size(x)$ $size(y)$ 是以 $x$ 为根时子树的大小。$size'(x)$ $size'(y)$ 是以 $y$ 为根时子树的大小。  

记 $f (x)$ $f(y)$ 是以 $x$ 为根时f子树的大小。$f'(x)$ $f'(y)$ 是以 $y$ 为根时子树的大小。  
$$
size'(x) = size(x) - size(y)\\
size'(y) = size(x)\\
f'(x) = 1 + \sum_{y \in son'(x)}size(y) \times prime(size(y)) = 1 + f(x) - f(y) \times prime(size(y))\\
f'(y) = f(y) + f'(x) \times size'(x) = f(y) + (f(x) - f(y) \times size(y)) \times (n - size(y))\\
$$

#### hash支持删掉叶子节点的操作

##### [JSOI2016]独特的树叶

仍运用以下公式对树进行hash以判断树的同构性。
$$
f(x) = 1 + \sum_{y \in son(x)} f(y) \times prime(y)
$$
在树 $B$ 中枚举每一个叶子节点 , 检查去掉这个叶子节点之后是否能够使两棵树同构。具体地 , 在给 $A$ 节点加上一个叶子之后 , 所有其余节点为根的树的hash值均发生变化 , 我们在枚举去掉树 $B$ 的某个叶子时求出与该叶子相邻的点的hash值的变化 , 如果去掉的正是多出来的叶子 , 它应当在树 $A$ 中出现过一次。  

而删掉叶子节点时与叶子相邻节点为根的hash值变化正是该叶子节点的贡献 , 也就是 $1 \times prime(1) = 2$ 。因此hash值减小 $2$。  

```cpp
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 100010;

const int Mod = 998244353;
inline int Inc(int a, int b) { return (a += b) >= Mod ? a - Mod : a; }
inline int Dec(int a, int b) { return (a -= b) < 0 ? a + Mod : a; }
inline int Mul(int a, int b) { return 1ll * a * b % Mod; }

int Prime[N], vp[15 * N], top;
void seive(int n) {
	for(int i = 2; top < n; ++i) {
		if(!vp[i]) Prime[++top] = i;
		for(int j = 1; j <= top && i * Prime[j] <= 14 * N; ++j) {
			vp[i * Prime[j]] = 1;			
			if(!(i % Prime[j])) break;
		}
	}
}

int head[N], ver[N << 1], nex[N << 1], deg[N], tot;
inline void graphInit() {
	memset(head, -1, sizeof(head));
	tot = 0;
}
inline void addedge(int u, int v) {
	ver[tot] = v; nex[tot] = head[u]; head[u] = tot++;	
}
map<int, bool> hsh;
int f[N], siz[N], n;
void dfs1(int cur, int pre) {
	siz[cur] = f[cur] = 1;
	for(int i = head[cur]; ~i; i = nex[i])
		if(ver[i] != pre) {
			dfs1(ver[i], cur);
			siz[cur] += siz[ver[i]];
			f[cur] = Inc(f[cur], Mul(f[ver[i]], Prime[siz[ver[i]]]));
		}
}

void dfs2(int cur, int pre) {
	for(int i = head[cur]; ~i; i = nex[i])
		if(ver[i] != pre) {
			f[ver[i]] = Inc(f[ver[i]], Mul(Dec(f[cur], Mul(f[ver[i]], Prime[siz[ver[i]]])), Prime[n - siz[ver[i]]]));
			dfs2(ver[i], cur);
		}
}
int main() {
	int u, v;
	scanf("%d", &n);
	seive(n + 1);
	graphInit();
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; ++i) hsh.insert(pair<int, bool>(f[i], true));
	++n;
	graphInit();
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		addedge(u, v);
		addedge(v, u);
		++deg[u]; ++deg[v];
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; ++i) {
		if(deg[i] == 1 && hsh.find(f[ver[head[i]]] - 2) != hsh.end()) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
```



