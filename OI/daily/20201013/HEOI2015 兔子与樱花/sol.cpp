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

const int N = 2000010;
graph g;
int c[N], son[N], n, m, ans = 0;

void dfs(int cur) {
    for(int ver : g[cur]) dfs(ver);
    sort(g[cur].begin(), g[cur].end(), [&](int x, int y){ return c[x] + son[x] < c[y] + son[y]; });
    for(int i = 0; i < g[cur].size(); ++i) {
        int tar = g[cur][i];
        if(c[cur] + son[cur] + c[tar] + son[tar] - 1 <= m) {
            ++ans; c[cur] += c[tar]; son[cur] += son[tar] - 1;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int v;
    cin >> n >> m;
    g.resize(n+1);
    rep(i,1,n) cin >> c[i];
    rep(i,1,n) {
        cin >> son[i];
        rep(j,1,son[i]) {
            cin >> v;
            g[i].push_back(++v);
        }
    }
    // rep(i,1,n) {
    //     cout << i << ": ";
    //     repp(j,0,g[i].size()) cout << g[i][j] << ' ';
    //     cout << endl;
    // }
    dfs(1);
    cout << ans << endl;
    return 0;
}