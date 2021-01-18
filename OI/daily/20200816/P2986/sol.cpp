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

Graph G;

const int maxn = 100010;
int a[maxn], siz[maxn], root;
ll sum[maxn];

void dfs1(int cur, int pre) {
    siz[cur] = a[cur];
    for(auto e : G[cur])
        if(e.x != pre) {
            dfs1(e.x, cur);
            siz[cur] += siz[e.x];
            sum[cur] += sum[e.x] + 1ll * siz[e.x] * e.w;
        }
}

void dfs2(int cur, int pre) {
    for(auto e : G[cur])
        if(e.x != pre) {
            sum[e.x] = sum[cur] + 1ll * (siz[root] - 2 * siz[e.x]) * e.w;
            dfs2(e.x, cur);
        }
}

int main() {
    srand((unsigned)time(NULL));
    int n, u, v, w;
    cin >> n;
    G.resize(n + 1);
    rep(i,1,n) cin >> a[i];
    repp(i,1,n) {
        cin >> u >> v >> w;
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }
    root = (long long)rand() * rand() % n + 1;
    dfs1(root, 0);
    dfs2(root, 0);
    int ans = 1;
    for(int i = 2; i <= n; ++i) if(sum[ans] > sum[i]) ans = i;
    cout << sum[ans] << endl;
    return 0;
}