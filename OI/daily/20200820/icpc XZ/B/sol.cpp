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

const int N = 1000010, K = 3;
int g[N];
int f[N] = {1,1,2,6,24,72,180,428,1042,2512,5912,13592,30872,69560,155568,345282,761312, 1669612, 3645236, 7927404, 17180092};

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    g[0] = g[1] = g[2] = 1;
    int lmt = 1000000;
    for(int i = 3; i <= lmt; ++i) g[i] = Inc(g[i-1], g[i-3]);
   for(int n = 21; n <= lmt; ++n) {
       f[n] = Dec(Dec(Dec(Dec(Dec(Dec(Inc(Inc(Inc(Inc(Inc(Inc(Dec(Dec(Inc(Dec(Mul(3,f[n-1]), Mul(4,f[n-3])), Mul(3,f[n-4])), Mul(4,f[n-5])), Mul(9,f[n-6])), Mul(2,f[n-7])) + Mul(5,f[n-8]), Mul(9,f[n-9])), Mul(17,f[n-10])), Mul(16,f[n-11])), Mul(14,f[n-12])), Mul(8,f[n-13])), Mul(2,f[n-14])), Mul(5,f[n-15])), Mul(5,f[n-16])), Mul(6,f[n-17])), Mul(4,f[n-18])), f[n-19]);
       f[n] = (f[n] % Mod + Mod) % Mod;
   }
//    for(int i = 1; i <= 50; ++i) printf("%lld ", Mul(2, Dec(Inc(Inc(3*g[i], g[i-1]), g[i-2]), 2 + i))); printf("\n");
    int tests;
    cin >> tests;
    while(tests--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if(k == 1) printf("%d\n", n==1?1:2);
        else if(k == 2) { 
            if(n == 1) printf("1\n");
            else printf("%d\n", Mul(2, Dec(Inc(Inc(Mul(3, g[n]), g[n-1]), g[n-2]), 2 + n)));
        }
        else printf("%d\n", f[n]);
    }
    return 0;
}
