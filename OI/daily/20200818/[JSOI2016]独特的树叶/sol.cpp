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
