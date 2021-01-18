#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

struct edge {
    int x, w;
    edge() {}
    edge(int x, int w): x(x), w(w) {}
};
typedef vector< vector<edge> > Graph;

const int Mod = 998244353;

inline int Inc(int a, int b) {
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b) {
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b) {
    return 1ll * a * b % Mod;
}

const int base = 3, maxn = 200010;

int Pow[maxn], hsh[15][15], tp[15], stdd = 0, ans = 0, k;

void dfs(int depth) {
    if(depth == k + 1) {
        int cur = 0;
        for(int i = 1; i <= k; ++i) cur = Inc(cur, hsh[i][tp[i]]);
        if(cur == stdd) ++ans;
        return ;
    }
    for(int i = 1; i <= depth; ++i) {
        tp[depth] = i;
        dfs(depth + 1);
    }
}

Graph G;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m, u, v, w;
    cin >> n >> m >> k;
    G.resize(n + 1);
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(edge(v, w));
    }
    Pow[0] = 1; for(int i = 1; i <= n; ++i) Pow[i] = Mul(Pow[i-1], base);
    for(int i = 1; i <= n; ++i) {
        sort(G[i].begin(), G[i].end(), [&](edge& a, edge&b){ return a.w < b.w; });
        int s = G[i].size();
        for(int j = 0; j < s; ++j)
            hsh[s][j + 1] = Inc(hsh[s][j + 1], Pow[G[i][j].x]);
    }
    for(int i = 1; i <= n; ++i) stdd = Inc(stdd, Pow[i]);
    dfs(1);
    cout << ans << endl;
    return 0;
}