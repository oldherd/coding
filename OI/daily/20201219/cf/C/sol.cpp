#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ull;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int N = 200010;
ull a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        int n, m, b;
        cin >> n >> m;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];
        ll g = a[2] - a[1];
        rep(i,3,n) g = __gcd(g, a[i] - a[i-1]);
        rep(i,1,n) cout << __gcd(g, a[1] + b[i]) << ' ';
        cout << endl;
    }
    return 0;
}