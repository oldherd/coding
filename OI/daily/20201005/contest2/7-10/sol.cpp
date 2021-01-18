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

const int N = 110;
int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int wt[N][N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    rep(i,1,n) fa[i] = i;
    rep(i,1,m) {
        cin >> u >> v >> w;
        wt[u][v] = wt[v][u] = w;
        if(w == 1) {
            u = find(u); v = find(v);
            fa[u] = v;
        }
    }
    rep(i,1,k) {
        cin >> u >> v;
        if(wt[u][v] == -1) {
            u = find(u); v = find(v);
            if(u == v) cout << "OK but..." << endl;
            else cout << "No way" << endl;
        } else if(wt[u][v] == 0) {
            u = find(u); v = find(v);
            if(u == v) cout << "No problem" << endl;
            else cout << "OK" << endl;
        } else cout << "No problem" << endl;
    }
    return 0;
}