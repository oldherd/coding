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

inline int De2Mul(int a , int b) {
    return a % 2 ? Mul(a , b / 2) : Mul(a / 2 , b);
}

const int N = 100010;
int a[N] , fac[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    a[1] = 1; a[2] = 1; a[3] = 9;
    fac[1] = 1; fac[2] = 2; fac[3] = 6;
    rep(i,3,100000) {
        a[i] = Inc(Mul(a[i-1] , i) , Mul(fac[i-1] , De2Mul(i , i-1)));
        fac[i] = Mul(fac[i-1] , i);
    }
    while(tests--) {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}