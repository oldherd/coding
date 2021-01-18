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

const int N = 2010 , M = 2010;
int f[M] , w[N] , g[M];

const int Mod = 10;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    f[0] = 1;
    int n , m;
    cin >> n >> m;
    rep(i,1,n) cin >> w[i];
    rep(i,1,n) per(j,m,w[i]) f[j] = Inc(f[j] , f[j-w[i]]); 
    rep(i,1,n) {
        memcpy(g , f , sizeof(f));
        rep(j,w[i],m) g[j] = Dec(g[j] , g[j-w[i]]);
        rep(i,1,m) cout << g[i];
        cout << endl;
    }  
    return 0;
}