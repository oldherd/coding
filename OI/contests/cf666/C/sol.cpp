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

const int maxn = 100010;
long long a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    long long n;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    if(n == 1) {
        cout << 1 << ' ' << 1 << endl;
        cout << -a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << -a[1] << endl;
    } else {
        cout << n << ' ' << n << endl;
        cout << n - a[n] << endl;
        cout << 1 << ' ' << n - 1 << endl;
        rep(i,1,n-1) {
            cout << ((n - 1) * a[i]) << ' ';
        }
        cout << endl;
        a[n] = n;
        cout << 1 << ' ' << n << endl;
        rep(i,1,n-1) {
            cout << -n * a[i] << ' ';
        }
		cout << -n << endl;
        cout << endl;
    }
    return 0;
}
