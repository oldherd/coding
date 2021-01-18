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
const int N = 100010;
int ind[N] , dep[N];

void dfs(int cur , int pre) {
    dep[cur] = dep[pre] + 1;
    for(int ver : g[cur]) dfs(ver , cur);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , k , tmp , root;
    cin >> n;
    g.resize(n + 1);
    rep(i,1,n) {
        cin >> k;
        rep(j,1,k) {
            cin >> tmp;
            g[i].push_back(tmp);
            ++ind[tmp];
        }
    }
    rep(i,1,n) if(!ind[i]) root = i;
    dfs(root , 0);
    int ans = root;
    rep(i,1,n) if(dep[i] > dep[ans]) ans = i;
    cout << ans << endl;
    return 0;
}