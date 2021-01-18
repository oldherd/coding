/*
  sol.cpp -- [NOIP2014 tg] xunzhaodaolu
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)
#define pb push_back
#define rz resize

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<ldb> VD;


vector< VI > g, _g;

const int N = 10010;
bool vis[N], to[N];

void dfs(int cur) {
    vis[cur] = true;
    for(int ver : _g[cur]) if(!vis[ver]) dfs(ver);
}


queue<int> q;
int dis[N];
void bfs(int start) {
    dis[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        // cout << cur << endl;
        for(int ver : g[cur]) {
            // cout << ver << ' ' << dis[ver] << endl;
            if(to[ver] && dis[ver] > 1 + dis[cur]) {
                dis[ver] = dis[cur] + 1;
                q.push(ver);
            }
        }
    }
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 1;
    //int Mod = ;
    rep(i,1,tests) {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        int n, m, u, v;
        cin >> n >> m;
        g.resize(n + 1);
        _g.resize(n + 1);
        rep(i,1,m) {
            cin >> u >> v;
            g[u].pb(v);
            _g[v].pb(u);
        }
        cin >> u >> v;
        dfs(v);
        rep(i,1,n) {
            to[i] = true;
            for(int ver : g[i])
                if(!vis[ver]) {
                    to[i] = false;
                }
        }
        bfs(u);
        // rep(i,1,n) cout << to[i] << ' '; cout << endl;
        if(dis[v] >= 0x3f3f3f3f) cout << -1 << endl;
        else cout << dis[v] << endl;
    }
    return 0;
}
