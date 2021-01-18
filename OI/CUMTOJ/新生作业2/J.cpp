#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)
#define inl inline

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int inf = 0x7f7f7f7f;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n , ans = inf;
        cin >> n;
        for(int i = 0; i * 200 <= n; ++i) {
            int t = n - i * 200;
            // if(t - t / 150 * 150 == 0) cout << t << ' ' << i << ' ' << t / 150 << endl;
            ans = min(ans , t - t / 150 * 150);
        }
        cout << ans << endl;
    }
    return 0;
}