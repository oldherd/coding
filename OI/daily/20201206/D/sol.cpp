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

const int C[2][2] = {
    {1, 0},
    {1, 1},
}, Mod = 2;

int binom(int n, int m) {
    if(m == 0 || n == m) return 1;
    if(n == 0) return 0;
    return binom(n / Mod, m / Mod) * C[n%Mod][m%Mod] % Mod;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        // cout << n - 2 - (m-1) * (k-1) << ' ' << m - 2 << endl;
        if(binom(n - 2 - (m-1) * (k-1), m - 2)) {
            cout << "yes\n";
        } else cout << "no\n";
    }
    return 0;
}