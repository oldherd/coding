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

const int Mod = 998244353;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

const int N = 100010;
int f[N] , g[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    f[0] = f[1] = 0; f[2] = 6;
    g[0] = g[1] = g[2] = 0; g[3] = 6;
    rep(i,2,100005) f[i] = Inc(Mul(f[i-1] , 2) , 6);
    rep(i,4,100005) g[i] = Inc(Mul(g[i-1] , 3) , f[i-1]);
    // rep(i,1,10) cout << f[i] << ' ';
    // cout << endl;
    // rep(i,1,10) cout << g[i] << ' ';
    // cout << endl;
    while(tests--) {
        int n;
        cin >> n;
        cout << Inc(g[n] , 3) << endl;
    }
    return 0;
}