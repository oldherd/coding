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
int Pow(int a, int b) {
    long long res = 1 % Mod;
    for(; b; b >>= 1) {
        if(b&1) res = res * a % Mod;
        a = (long long)a * a % Mod;
    }
    return res;
}

const int N = 1234;
int a[N] , f[N];
int inv[10];

inline int nex(int id) { return a[id] == 2 ? 0 : (a[id] == 0 ? 1 : 2); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    rep(i,1,6) inv[i] = Pow(i , Mod - 2);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        rep(i,1,n) cin >> a[i];
        memset(f , 0 , sizeof(f));
        rep(i,1,n) {
            int len = min(i , 6);
            rep(j,max(0,i-6),i-1) f[i] = Inc(f[i] , Inc(f[j] , nex(j)));
            f[i] = Mul(f[i] , inv[len]);
        }
        cout << f[n] << endl;
    }
    return 0;
}