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

const int inf = 0x7f7f7f7f;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n , mx = -1 , mn = inf , tmp;
        cin >> n;
        rep(i,1,n) {
            cin >> tmp;
            mx = max(mx , tmp);
            mn = min(mn , tmp);
        }
        cout << 2 * (mx - mn) << endl;
    }
    return 0;
}