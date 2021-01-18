#include <bits/stdc++.h>

using namespace std;

const int N = 250010, inf = 0x3f3f3f3f;

struct edge {
    int x, w;
    edge() {}
    edge(int x, int w) : x(x), w(w) {}
};

typedef vector< vector<edge> > Graph;
typedef vector< vector<int> > graph;
typedef long long ll;
Graph G;
graph g;

int dfn[N], idfn[N], siz[N], top[N], fa[N], mc[N], dep[N], ms[N], dfs_clock = 0;
void dfs1(int cur, int pre) {
    siz[cur] = 1; dep[cur] = dep[pre] + 1; fa[cur] = pre;
    for(edge e : G[cur]) if(e.x != pre) {
        ms[e.x] = min(e.w, ms[cur]);
        dfs1(e.x, cur);
        siz[cur] += siz[e.x];
        if(!mc[cur] || siz[e.x] > siz[mc[cur]]) mc[cur] = e.x;
    }
}
void dfs2(int cur, int tp) {
    top[cur] = tp; dfn[cur] = ++dfs_clock; idfn[dfs_clock] = cur;
    if(mc[cur]) dfs2(mc[cur], tp);
    for(edge e : G[cur]) if(e.x != fa[cur] && e.x != mc[cur]) dfs2(e.x, e.x);
}

int genlca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int ks[N], inK[N];
bool cmper(int x, int y) { return dfn[x] < dfn[y]; }
int stk[N], stop;
int indd[N<<1], itop;

void insert(int x) {
    indd[++itop] = x;
    int lca = genlca(x, stk[stop]);
    if(lca == stk[stop]) return (void)(stk[++stop] = x);
    while(dfn[stk[stop-1]] >= dfn[lca]) g[stk[stop-1]].push_back(stk[stop]), --stop;
    if(lca != stk[stop]) g[lca].push_back(stk[stop]), stk[stop] = lca, indd[++itop] = lca;
    stk[++stop] = x;
}

ll dp[N];
void dfs3(int cur) {
    dp[cur] = 0;
    for(int ver : g[cur]) {
        dfs3(ver);
        if(inK[ver]) dp[cur] += ms[ver];
        else dp[cur] += min(dp[ver], (ll)ms[ver]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v, w;
    cin >> n;
    G.resize(n+1);
    g.resize(n+1);
    for(int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }
    ms[1] = inf;
    dfs1(1, 0);
    dfs2(1, 1);
    int q;
    cin >> q;
    for(int cs = 1; cs <= q; ++cs) {
        // g.clear(); g.resize(n+1);
        int k; cin >> k;
        for(int i = 1; i <= k; ++i) cin >> ks[i], inK[ks[i]] = 1;
        sort(ks+1, ks+k+1, cmper);
        stk[stop = 1] = 1; itop = 0;
        for(int i = 1; i <= k; ++i) insert(ks[i]);//, g[ks[i]].clear();
        while(stop-1) g[stk[stop-1]].push_back(stk[stop]), --stop;
        dfs3(1);
        // cout << "cs = " << cs << endl;
        // for(int i = 1; i <= n; ++i)
        //     for(int ver : g[i]) cout << '(' << i << ',' << ver << ") ";
        // cout << "virtual tree ends." << endl;
        // for(int i = 1; i <= n; ++i) cout << ms[i] << ' '; cout << endl;
        for(int i = 1; i <= k; ++i) inK[ks[i]] = 0;
        for(int i = 1; i <= itop; ++i) g[indd[i]].clear();
        g[1].clear();
        // cout << endl;
        // cout << dp[1] << endl;
        // for(int i = 1; i <= n; ++i) cout << dp[i] << ' '; cout << endl;
        cout << dp[1] << endl;
    }
    return 0;
}