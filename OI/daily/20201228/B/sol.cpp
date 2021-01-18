#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n, m, ma = 0, mb = 0, t1 = 0, t2 = 0;
        cin >> n;
        rep(i,1,n) {
            cin >> t1; t2 += t1;
            ma = max(ma, t2);
        }
        t1 = t2 = 0;
        cin >> m;
        rep(i,1,m) {
            cin >> t1; t2 += t1;
            mb = max(mb, t2);
        }
        cout << max(ma, max(mb, ma + mb)) << endl;
    }
    return 0;
}