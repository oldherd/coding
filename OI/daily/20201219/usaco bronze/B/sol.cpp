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

int a[1010];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n; cin >> n;
    int ans = 0;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
        rep(j,i,n) {
            int t = 0;
            rep(k,i,j) t += a[k];
            if(t % (j-i+1)) continue;
            t /= (j-i+1);
            bool flg = false;
            rep(k,i,j) if(a[k] == t) flg = true;
            if(flg) ++ans;
        }
    cout << ans << endl;
    return 0;
}