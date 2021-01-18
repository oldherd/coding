#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

struct edge {
	int x, w;
	edge() {}
	edge(int x, int w): x(x), w(w) {}
    bool operator < (const edge& o) const { return w < o.w; }
};

const int maxn = 200010;

typedef vector< vector<edge> > Graph;
Graph G;
int odg[maxn], n;

int vis[maxn], rest[maxn], tp[15], ans = 0, k, vis_clock = 1, rest_clock, st, s2; 

// bool check() {
//     for(int i = 1; i <= n; ++i)
//         if(vis[i] != vis_clock) {
//             s = i; vis[i] = vis_clock;
//             if(!dfs(i)) return false;
//         }
//     return true;
// }

// void mj(int depth) {
//     if(depth == k + 1) {
//         if(check()) ++ans;
//         ++vis_clock;
//         return ;
//     }
//     for(int i = 0; i < depth; ++i) {
//         tp[depth] = i;
//         mj(depth + 1);
//     }
// }

bool dfs2(int cur) {
    int ver = G[cur][tp[odg[cur]]].x;
    if(vis[ver] == vis_clock || rest[ver] == rest_clock)
        return s2 == ver;
    rest[ver] = rest_clock;
    dfs2(ver);
}

void check_rest() {
    ++rest_clock;
    for(int i = 1; i <= n; ++i) if(vis[i] != vis_clock && rest[i] != rest_clock) {
        s2 = i; rest[i] = rest_clock;
        if(!dfs2(i)) return;
    }
    ++ans;
}

void dfs1(int cur) {
    if(tp[odg[cur]]) {
        int ver = G[cur][tp[odg[cur]] - 1].x;
        if(vis[ver] == vis_clock) {
            if(ver == st) check_rest();
            return;
        }
        vis[ver] = vis_clock;
        dfs1(ver);
        vis[ver] = 0;
    } else {
        for(int i = 1; i <= odg[cur]; ++i) {
            tp[odg[cur]] = i;
            int ver = G[cur][i - 1].x;
            if(vis[ver] == vis_clock) {
                if(ver == st) check_rest();
                continue;
            }
            vis[ver] = vis_clock;
            dfs1(ver);
            vis[ver] = 0;
        }
        tp[odg[cur]] = 0;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int m, u, v, w;
    cin >> n >> m >> k;
    G.resize(n + 1);
    st = (long long)rand() * rand() % n + 1;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(edge(v, w));
        ++odg[u];
    }
    for(int i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
    ans = 0;
    vis[st] = vis_clock;
    dfs1(st); 
    cout << ans << endl;
    return 0;
}
