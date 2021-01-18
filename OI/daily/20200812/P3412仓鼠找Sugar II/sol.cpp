#include <bits/stdc++.h>

using namespace std;

const int Mod = 998244353;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<int> > Graph;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

int Pow(int a, int b) {
	ll res = 1 % Mod;
	for(; b; b >>= 1) {
		if(b&1) res = res * a % Mod;
		a = (long long)a * a % Mod;
	}
    return res;
}

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

const int maxn = 100010;

Graph G;
int size[maxn], dg[maxn], f[maxn], g[maxn], sf[maxn], sg[maxn], sumf[maxn], n;

void dfs1(int cur, int pre) {
    f[cur] = dg[cur];
    sumf[cur] = 0;
    size[cur] = 1;
    for(auto ver : G[cur]) 
        if(ver != pre) {
        dfs1(ver, cur);
        f[cur] = Inc(f[cur], f[ver]);
        sf[cur] = Inc(sf[cur], Inc(sf[ver], Mul(f[ver], size[ver])));
        size[cur] = Inc(size[cur], size[ver]);
        sumf[cur] = Inc(sumf[cur], f[ver]);
    }
}

void dfs2(int cur, int pre) {
    g[cur] = Inc(Inc(Dec(sumf[pre], f[cur]), dg[pre]), g[pre]);
    sg[cur] = Inc(Inc(sg[pre], Dec(sf[pre], (Inc(sf[cur], Mul(size[cur], f[cur]))))), Mul(g[cur], n - size[cur]));
    for(auto ver : G[cur])
        if(ver != pre) {
        dfs2(ver, cur);   
    }
}

int main() {
    srand((unsigned)time(NULL));
    int u, v;
    cin >> n;
    G.resize(n + 1);
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++dg[u]; ++dg[v];
    }
    int root = 1;
    dfs1(root, 0);
    sf[0] = Inc(sf[root], Mul(size[root], f[root]));
    sumf[0] = f[root];
    dfs2(root, 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = Inc(ans, Inc(sf[i], sg[i]));
    cout << Mul(ans, Pow(Mul(n,n), Mod - 2)) << endl;
    return 0;
}