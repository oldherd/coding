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

const int N = 510;
int f[N][N], a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    rep(i,1,n) cin >> a[i], f[i][0] = 1;
    // f[0][0] = 1;
    rep(i,1,n) {
        //     rep(j,0,k) {
        //     rep(i,1,n) cout << f[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;
        if(i==3) {
            int t = i;
            t = i;
        }
        int l, r;
        for(l = i; l > 1 && a[l-1] < a[i]; --l);
        for(r = i; r < n && a[r+1] < a[i]; ++r);
        // cout << l << ' ' << r << endl;
        per(j,k,1) {
            int preSum = 0;
            per(p,r,l) {
                // preSum += f[p-1][j-1];
                // f[p][j] += p != i ? preSum : preSum - f[p-1][j-1] + f[p-1][j];
                // rep(tt,l-1,p-2) f[p][j] += f[tt][j-1];
                // f[p][j] += f[i-1][i==p?j:j-1];
                // rep(tt,l-1,p-1) if(tt!=i-1) f[p][j] += f[tt][j-1];
                // if(i-1 >= l-1 && i-1 <= p-1) f[p][j] += f[i-1][j];
                // rep(tt,l-1,p-1) f[p][j] += f[tt][(p==i&&tt==i-1)?j:j-1];
                if(p==i) {
                    rep(tt,l-1,i-2) f[p][j] += f[tt][j-1];
                    f[p][j] += f[i-1][j];
                } else {
                    rep(tt,l-1,p-1) f[p][j] += f[tt][j-1];
                }
            }
        }
    }
    rep(j,0,k) {
        rep(i,1,n) cout << f[i][j] << ' ';
        cout << endl;
    }
    int ans = 0;
    rep(i,0,k) ans += f[n][i];
    cout << ans << endl;
    return 0;
}