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

const int N = 10010;

Graph g;
bool flg = true;
int vis[N], nex[N], dis[N];
int dfs(int cur, int pre, int clock) {
    if(vis[cur]) return clock;
    vis[cur] = 1; dis[cur] = clock;
    for(int ver: g[cur]) if(ver != pre) {
        nex[cur] = ver; return dfs(ver, cur, clock+1);
    }
    flg = false;
    return clock;
}

int dfs2(int cur, int pre, int clock) {
    if(vis[cur]) return clock;
    vis[cur] = 1; dis[cur] = clock;
    int ct = -1;
    for(int ver: g[cur]) if(ver != pre) {
        nex[cur] = ver, ct = max(dfs(ver, cur, clock+1), ct);
    }
    if(ct > 0) return ct;
    flg = false;
    return clock;
}


int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    g.resize(n + 1);
    rep(i,1,m) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i,1,k) {
        flg = true;
        memset(vis, 0, sizeof(vis));
        memset(nex, 0, sizeof(nex));
        memset(dis, 0, sizeof(dis));
        int tmp;
        cin >> tmp;
        // vis[tmp] = 1;
        // if(tmp == 4) {
        //     rep(i,1,n) cout << dis[i] << ' '; cout << endl;
        // }
        int len = dfs(tmp, 0, 1);
        // cout << flg << ' ' << len << endl;
        if(flg) {
            if(len % 2 == 0) {
                int t = len / 2 - 1, p = tmp;
                rep(i,1,t) p = nex[p];
                p = min(p, nex[p]);
                cout << p << endl;
            } else {
                int t = len / 2 , p = tmp;
                rep(i,1,t) p = nex[p];
                cout << p << endl;
            }
        } else {
            memset(vis, 0, sizeof(vis));
        memset(nex, 0, sizeof(nex));
        memset(dis, 0, sizeof(dis));
                int len = dfs2(tmp, 0, 1);
            if(len == 1) cout << '0' << endl;
            else {
                int p = tmp;
                rep(i,1,n) if(dis[i] > dis[p] || dis[i] == dis[p] && i < p) p = i;
                cout << p << endl;
            }
        }
    }
    return 0;
}