#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)
#define inl inline

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<int> > Graph;

map<int,int> h;
const int N = 500010 , Mod[] = { 998244353 , 1000000009 , 1000000007 } , sizeMod = 3;
int a[N] , f[N][3];
Graph g;

struct node {
    int x , y , z;
    node() {}
    node(int x , int y , int z) : x(x) , y(y) , z(z) {}
    bool operator < ( const node& o ) const { return x < o.x || (x == o.x && (y < o.y || (y == o.y && z < o.z))); }
    bool operator == (const node& o) const { return x == o.x && y == o.y && z == o.z; }
} ns[N];

inl int Mul(int a , int b , int Mod) { return (ll)a * b % Mod; }

void dfs(int cur , int pre) {
    int sz = g[cur].size();
    for(int ver : g[cur]) {
        repp(i,0,sizeMod) f[ver][i] = Mul(f[cur][i] , sz, Mod[i]);
        dfs(ver , cur);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n , u , v;
    cin >> n;
    g.resize(n + 1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n-1) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    repp(i,0,sizeMod) f[1][i] = 1;
    dfs(1 , 0);
    rep(i,1,n) repp(j,0,sizeMod) f[i][j] = Mul(f[i][j] , a[i], Mod[j]);
    rep(i,1,n) ns[i].x = f[i][0] , ns[i].y = f[i][1] , ns[i].z = f[i][2];
    sort(ns + 1 , ns + n + 1);
    int inf = Mod[1] + 10;
    ns[n+1] = node(inf,inf,inf);
    int cnt = 1 , ans = 0;
    rep(i,2,n+1) {
        if(ns[i] == ns[i-1]) ++cnt;
        else {
            ans = max(ans , cnt);
            cnt = 1;
        }
    }
    cout << n - ans << endl;
    return 0;
}