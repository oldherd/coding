#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int Prime[maxn], v[15 * maxn], tot = 0;
inline void seive() {
	for(int i = 2; i <= 1500000; ++i) {
		if(!v[i]) Prime[++tot] = i;
		for(int j = 1; j <= tot && i * Prime[j] <= 1500000; ++j) {
            v[i * Prime[j]] = 1; if(!(i % Prime[j])) break;
        }
	}
}

const int Mod = 1000000007;
inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

typedef vector< vector<int> > Graph;
Graph G;
int f[2][maxn], siz[maxn], n, id;

void dfs1(int cur, int pre) {
    siz[cur] = f[id][cur] = 1;
    for(auto ver : G[cur])
        if(ver != pre) {
            dfs1(ver, cur);
            siz[cur] += siz[ver];
            f[id][cur] = Inc(f[id][cur], Mul(f[id][ver], Prime[siz[ver]]));
        }
}

void dfs2(int cur, int pre) {
    for(auto ver : G[cur])
        if(ver != pre) {
            f[id][ver] = Inc(f[id][ver], Mul(Dec(f[id][cur], Mul(f[id][ver], Prime[siz[ver]])), Prime[n - siz[ver]]));
            dfs2(ver, cur);
        }
}

void work(int n) {
    int u, v;
    G.assign(n + 1, vector<int>()) ;
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root = (long long)rand() * rand() % n + 1;
    dfs1(root, 0);
    dfs2(root, 0);
    sort(&f[id][1], &f[id][n+1]);
}

int __;
int main() {
    seive();
    for(scanf("%d", &__); __; __--) {
        scanf("%d", &n);
        id = 0; work(n);
        id = 1; work(n);
        bool flg = true;
        for(int i = 1; i <= n; ++i)
            if(f[0][i] != f[1][i]) {
                flg = false;
                break;
            }
        if(flg) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}