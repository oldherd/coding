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

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int a[100], b[100];
    int n, m;
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    rep(i,1,m) {
        int g = 0;
        rep(j,1,n) g = __gcd(a[j] + b[i], g);
        cout << g << ' ';
    }
    return 0;
}