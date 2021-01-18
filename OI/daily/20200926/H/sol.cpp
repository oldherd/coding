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

const int N = 100010 , NN = N - 10;
int cnt[N] , p = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int tests , tmp;
    cin >> tests;
    while(tests--) {
        ll ans = 0;
        memset(cnt , 0 , sizeof(cnt));
        int n; cin >> n;
        rep(i,1,n) { cin >> tmp; ++cnt[tmp]; }
        rep(i,1,NN)
            rep(j,1,NN/i)
                ans += (ll)cnt[i]*cnt[j]*cnt[i*j];
        cout << ans << endl;
    }
    return 0;
}