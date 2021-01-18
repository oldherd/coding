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

const int maxn = 210;
int r[maxn], g[maxn], b[maxn];
ll f[maxn][maxn][maxn];
int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int nr, ng, nb;
    ll ans = 0;
    cin >> nr >> ng >> nb;
    for(int i = 1; i <= nr; ++i) cin >> r[i];
    for(int i = 1; i <= ng; ++i) cin >> g[i];
    for(int i = 1; i <= nb; ++i) cin >> b[i];
    sort(r + 1, r + nr + 1, [&](int i, int j){return i > j;});
    sort(g + 1, g + ng + 1, [&](int i, int j){return i > j;});
    sort(b + 1, b + nb + 1, [&](int i, int j){return i > j;});
   	for(int i = 0; i <= nr; ++i)
   		for(int j = 0; j <= ng; ++j)
   			for(int k = 0; k <= nb; ++k)
			   if(i + j + k >= 2) {
   					if(i >= 1 && j >= 1) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + r[i]*g[j]);
   					if(j >= 1 && k >= 1) f[i][j][k] = max(f[i][j][k], f[i][j-1][k-1] + g[j]*b[k]);
   					if(i >= 1 && k >= 1) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + r[i]*b[k]);
   					ans = max(ans, 1ll*f[i][j][k]);
   				}
    cout << ans << endl;
    return 0;
}
