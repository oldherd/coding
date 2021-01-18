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

const int inf = 0x7f7f7f7f , maxn = 310;

Graph g;

int depth[maxn];
void dfs1(int cur , int pre , int wei) {
    depth[cur] = depth[pre] + wei;
    for(auto edge : g[cur])
        if(edge.x != pre)
            dfs1(edge.x , cur , edge.w);
}

int stk[maxn] , w[maxn] , isD[maxn] , top;
void findD(int cur , int pre , int wei) {
    w[top] = wei; stk[++top] = cur; isD[cur] = 1;
    int maxDepth = 0 , toPoint = 0 , wt = 0;
    for(auto edge : g[cur])
        if(edge.x != pre && maxDepth < depth[edge.x]) {
            toPoint = edge.x; maxDepth = depth[edge.x]; wt = edge.w;
        }
    if(toPoint) findD(toPoint , cur , wt);
}

int siz[maxn] , dis[maxn];
void dfs2(int cur , int pre , int wei) {
    dis[cur] = 0; siz[cur] = 1;
    for(auto edge : g[cur])
        if(edge.x != pre && !isD[edge.x]) {
            dfs2(edge.x , cur , edge.w);
            siz[cur] += siz[edge.x];
            dis[cur] += siz[edge.x] * edge.w + dis[edge.x];
        }
}

int sizLeft[maxn] , sizRight[maxn] , moveLeft[maxn] , moveRight[maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , s , u , v , wt;
    cin >> n >> s;
    g.resize(n + 1);
    rep(i,1,n-1) {
        cin >> u >> v >> wt;
        g[u].push_back(edge(v , wt));
        g[v].push_back(edge(u , wt));
    }
    dfs1(1 , 0 , 0);
        // rep(i,1,n) cout << depth[i] << ' '; cout << endl;
    int p1 = 1; rep(i,2,n) if(depth[i] > depth[p1]) p1 = i;
    dfs1(p1 , 0 , 0);
    // rep(i,1,n) cout << depth[i] << ' '; cout << endl;
    findD(p1 , 0 , 0);
    int ans = inf;
    int toD = 0;
    rep(i,1,top) 
        dfs2(stk[i] , 0 , 0) , toD += dis[stk[i]];
    int r = 1 , disT = 0;
    rep(i,1,top) sizLeft[i] = sizLeft[i-1] + siz[stk[i]] , moveLeft[i] = moveLeft[i-1] + sizLeft[i-1] * w[i-1];
    per(i,top,1) sizRight[i] = sizRight[i+1] + siz[stk[i]] , moveRight[i] = moveRight[i+1] + sizRight[i+1] * w[i];
    rep(l,1,n-1) {
        while(r < n && disT + w[r] <= s) disT += w[r] , ++r;
        ans = min(ans , moveLeft[l] + moveRight[r]);
        disT -= w[l];
    }
    // rep(i,1,top) cout << stk[i] << ' '; cout << endl;
    // cout << toD << endl;
    // rep(i,1,top) cout << dis[stk[i]] << ' '; cout << endl;
    // rep(i,1,top) cout << stk[i] << ' ' << siz[stk[i]] << ' ' << sizLeft[i] << ' ' << sizRight[i] << endl;
    // rep(i,1,top) cout << siz[stk[i]] << ' '; cout << endl;
    // rep(i,1,top) cout << w[i] << ' '; cout << endl;
    // rep(i,1,top) cout << moveLeft[i] << ' '; cout << endl;
    // rep(i,1,top) cout << moveRight[i] << ' '; cout << endl;
    cout << ans + toD << endl;
    return 0;
}