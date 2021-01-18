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

map<int,int> h, l, r;

const int Mod = 1000000007;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

void work(int n) {
    if(h[n]) return;
    work(n/2);
    work((1 + n) >> 1);
    work(n - ((1 + n) >> 1));
    // h[n] = Inc(Inc(h[n>>1], h[n - ((1 + n) >> 1)]), Mul(l[n>>1], r[n - ((1 + n) >> 1)]));
    h[n] = Inc(Inc(h[(n+1)>>1], h[n-(n>>1)]), Mul(r[(n+1)>>1] , l[n-(n>>1)]));
    l[n] = Inc(l[(n+1)>>1], Inc(l[n-(n>>1)], Mod - 1));
    r[n] = Inc(r[(n+1)>>1], Inc(r[n-(n>>1)], Mod - 1));
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    h[1] = l[1] = r[1] = 1;
    while(tests--) {
        int n;
        cin >> n;
        work(n);
        // for(int i = 1; i <= 3; ++i) cout << h[i] << ' '; cout << endl;
        // for(int i = 1; i <= 3; ++i) cout << l[i] << ' '; cout << endl;
        // for(int i = 1; i <= 3; ++i) cout << r[i] << ' '; cout << endl;
        cout << h[n] << endl;
    }
    return 0;
}