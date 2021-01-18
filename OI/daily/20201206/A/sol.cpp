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

double f(int n, int x) {
    return (200 * n - 100 * x) * pow(1.1,x);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(6);
    int n;
    double ans = 0;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        ans = max(ans, f(n, i));
    }
    cout << ans << endl;
    return 0;
}