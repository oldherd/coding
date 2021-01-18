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

const int N = 200010;
int h[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n, k;
        cin >> n >> k;
        rep(i,1,n) cin >> h[i];
        int ll = h[1] - k + 1, lr = h[1] + k - 1;
        bool flg = true;
        rep(i,2,n-1) {
//       	cout << ll << ' ' << lr << endl;
            if(h[i] > lr || h[i] + k - 1 < ll) {
                flg = false; break;
            }
            int l = max(ll, h[i]), r = min(lr, h[i] + k - 1);
            ll = l - k + 1; lr = r + k - 1;
        }
//       cout << ll << ' ' << lr << endl;
        if(flg) {
            if(h[n] <= lr && h[n] >= ll)
                cout << "yes\n";
            else cout << "no\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
