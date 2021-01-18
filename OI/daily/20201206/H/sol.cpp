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

typedef vector< vector<int> > Graph;
Graph g;

const int N = 500010;
int ans = 0;

int fa[N], siz[N], son[N], dfn[N], idfn[N], top[N], dep[N], dfs_clock;
void dfs1(int cur, int pre) {
    fa[cur] = pre; dep[cur] = dep[pre] + 1; siz[cur] = 1;
    for(int ver : g[cur]) {
        dfs1(ver, cur);
        siz[cur] += siz[ver];
        if(!son[cur] || siz[son[cur]] < siz[ver]) son[cur] = ver;
    }
}

void dfs2(int cur, int tp) {
    top[cur] = tp; dfn[cur] = ++dfs_clock; idfn[dfs_clock] = cur;
    if(!son[cur]) return;
    dfs2(son[cur], tp);
    for(int ver : g[cur]) if(ver != son[cur]) dfs2(ver, ver);
}

int dat[N<<2];
inline void update(int p) { dat[p] = max(dat[p<<1], dat[p<<1|1]); }
void insert(int p, int lp, int rp, int x, int v) {
    if(lp == rp) { dat[p] = v; return; }
    int mid = lp+rp>>1;
    if(x<=mid) insert(p<<1,lp,mid,x,v);
    if(x>mid) insert(p<<1|1,mid+1,rp,x,v);
    update(p);
}
int query(int p, int lp, int rp, int l, int r) {
    if(l <= lp && rp <= r) return dat[p];
    int mid = lp+rp>>1, ans = 0;
    if(l <= mid) ans = query(p<<1,lp,mid,l,r);
    if(r > mid) ans = max(ans, query(p<<1|1,mid+1,rp,l,r));
    return ans;
}

int qry(int x, int n) {
    int ans = 0; x = fa[x];
    while(top[x] != 1) {
        ans = max(ans, query(1, 1, n, dfn[top[x]], dfn[x])); x = fa[top[x]];
    }
    return max(ans, query(1, 1, n, dfn[1], dfn[x]));
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m, tar, tmp;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 2; i <= n; ++i) {
        cin >> tar;
        g[tar].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    // for(int i = 1; i <= n; ++i) cout << dfn[i] << ' '; cout << endl;
    int ans = 0, t_ans = 0;
    for(int i = 1; i <= m; ++i) {
        cin >> tmp;
        t_ans = (tmp==1?0:qry(tmp, n)) + 1;
        insert(1, 1, n, dfn[tmp], t_ans);
        ans = max(ans, t_ans);
    }
    cout << ans << endl;
    return 0;
}