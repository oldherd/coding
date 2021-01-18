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

const int N = 51000;

int cit[N] , n , m , u , v;

Graph g;

void dfs(int cur , int pre) {
    int sz = g[cur].size();
    for(int i = 0; i < sz ; ++i) {
        int ver = g[cur][i];
        if(ver == pre) continue;
        dfs(ver , cur);
        cit[cur] |= cit[ver];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int tmp;
        cin >> n >> m;
        g.clear();
        g.resize(n + 1);
        rep(i,1,n) cit[i] = 0;
        rep(i,1,n-1) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        rep(i,1,m) {
            cin >> tmp;
            cit[tmp] = 1;
        }
        dfs(1 , 0);
        int ans = 0;
        rep(i,2,n) if(cit[i]) ++ans;
        cout << (ans << 1) << endl;
    }
    return 0;
}