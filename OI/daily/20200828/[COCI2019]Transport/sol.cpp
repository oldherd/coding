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
int a[maxn];

void findroot(int xx) {
    
}

void dfs1(int xx) {
    xx = findroot(xx);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, u, v, w;
    scanf("%d", &n);
    G.resize(n + 1);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }
    int root = (long long)rand() * rand() % n + 1;
    dfs1(root, 0);
    return 0;
}
