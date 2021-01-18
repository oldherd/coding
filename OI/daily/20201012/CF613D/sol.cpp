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
typedef vector< vector<int> > graph;

const int N = 100010, inf = N + 10;

graph G, g;

int dfn[N], idfn[N], dep[N], fa[N], siz[N], mc[N], top[N], dfs_clock;
void dfs1(int cur, int pre) {
    dep[cur] = dep[pre] + 1; fa[cur] = pre;
    for(int ver : G[cur]) {
        dfs1(ver, cur);
        siz[cur] += siz[ver];
        if(!mc[cur] || siz[ver] > siz[mc[cur]]) mc[cur] = ver;
    }
}

void dfs2(int cur, int tp) {
    dfn[cur] = ++dfs_clock; idfn[dfs_clock] = cur; top[cur] = tp;
    if(mc[cur]) dfs2(mc[cur], tp);
    for(int ver : G[cur]) if(ver != fa[cur] && ver != mc[cur]) dfs2(ver, ver);
}

int genlca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int stk[N], indd[N], ks[N], ink[N], isVis[N], stop, itop;
void virtualTreeInsert(int x) {
    int lca = genlca(stk[stop], x);
    if(lca == stk[stop]) return (void)(stk[++stop] = x);
    while(dfn[lca] <= dfn[stk[stop-1]]) g[stk[stop-1]].push_back(stk[stop]), --stop;//使lca最终夹在stk[stop]和stk[stop-1]之间, 可能等于stk[stop].
    if(lca != stk[stop]) g[lca].push_back(stk[stop]), stk[stop] = lca;
    stk[++stop] = x;
}
void virtualTreeBuild(int k) {
    stk[stop = 1] = 1; itop = 0;
    rep(i,1,k) virtualTreeInsert(ks[i]);
    repp(i,1,stop) g[stk[i]].push_back(stk[i+1]);
}
 
void virtualTreeDelete(int k) {
    rep(i,1,k) ink[ks[i]] = 0;
    rep(i,1,itop) g[indd[i]].clear();
}

// bool flg;
int dp[N][2];
bool flg;
void dfs3(int cur) {
    dp[cur][0] = dp[cur][1] = 0;
    if(ink[cur]) dp[cur][0] = inf;
    int a1 = 0, a2 = 0;
    for(int ver : g[cur]) {
        dfs3(ver);
        if(ink[cur]) {
            dp[cur][1] += min(dp[ver][0], dp[ver][1] + 1);
        } else {
            dp[cur][1] += min(dp[ver][0], dp[ver][1]);
        }
    }
}

void solve(int n) {
    flg = true;
    dfs3(1);
    if(flg) cout << dp[1] << endl;
    else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, q, k, u, v;
    cin >> n;
    G.resize(n+1); g.resize(n+1);
    rep(i,1,n-1) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    rep(cs,1,q) {
        cin >> k;
        rep(i,1,k) cin >> ks[i];
        virtualTreeBuild(k);
        solve();
        virtualTreeDelete(k);
    }
    return 0;
}