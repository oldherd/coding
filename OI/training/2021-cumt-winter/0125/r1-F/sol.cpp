/*
  sol.cpp -- F - Sum of Maximum
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)
#define pb push_back
#define rz resize

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<ldb> VD;

template<class T> inline void read(T &x) {
    x = 0; char ch;
    do{ch=getchar();} while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(x&15),ch=getchar();} while(ch>='0'&&ch<='9');
}
int Mod = 1;
inline int Inc(int x, int y) { return (x += y) < Mod ? x : x - Mod; }
inline int Dec(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % Mod; }
inline int Power(int x, int y) {
    int ret = 1%Mod;
    for(; y; y>>=1) {
        if(y&1) ret=(ll)ret*x%Mod;
        x=(ll)x*x%Mod;
    }
    return ret;
}

template<class T> inline T abs(T x) { return x > 0 ? x : -x; }
template<class T> inline void cmin(T &x, T &y) { x = x > y ? y : x; }
template<class T> inline void cmax(T &x, T &y) { x = x > y ? x : y; }
template<class T> inline T min(T x, T y) { return x < y ? x : y; }
template<class T> inline T max(T x, T y) { return x > y ? x : y; }

template<class T>
class BIT { public:
    const int maxN;
    vector<T> c;
    BIT(int size) : maxN(size) { c.rz(size + 1); }
    void add(int x, T v) { for(; x <= maxN; x += x&(-x)) c[x] += v; }
    T qry(int x) { T ret = 0; for(; x; x -= x&(-x)) ret += c[x]; return ret; }
};

inline int inv(int x) {
    return Power(x, Mod - 2);
}

const int maxn = 1010;
int h[maxn], fac[maxn], f_raw[maxn];

int brute(int x, int k) {
    int ret = 0;
    rep(i,1,x) ret = Inc(ret, Dec(Power(i, k), Mul(2,Power(i-1, k-1))));
    return ret;
}

int calc(int x, int k) {
    if(k == 0) return 0;
    if(x <= k + 1) return brute(x, k);
    cout << '#';
    rep(i,1,k+1) f_raw[i] = brute(i, k), cout << i << ' ' << k << ' ' << f_raw[i] << ' ' << endl;
    int g = 1, rt = 0;
    rep(i,1,k+1) g = Mul(x - i, g);
    rep(i,1,k+1)
        rt = Inc(rt, Mul(Mul(Mul(f_raw[i], Power(x-i, Mod-2)), Mul(Power(i-1,Mod-2), Power(k+1-i, Mod-2))), (k+i-1)%2==0?1:Mod-1));
    return Mul(g, rt);
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    Mod = 1e9+7;
    fac[0] = fac[1] = 1;
    rep(i,2,1000) fac[i] = Mul(fac[i-1], i);
    int n;
    cout << calc(1, 0) << endl;
    while(~scanf("%d", &n)) {
        rep(i,1,n) scanf("%d", h+i);
        int ans = 0, par1 = 1;
        rep(i,1,n) {
            if(h[i] == h[i-1]) continue;
            int t = Mul(par1, n-i==0?1:Dec(calc(h[i], n-i+2), calc(h[i-1], n-i+2)));
            cout << calc(h[i], n-i+2) << ' ' << calc(h[i-1], n-i+2) << endl;
            ans = Inc(ans, t);
            par1 = Mul(par1, h[i]);
        }
        printf("#########%d\n", ans);
    }

    return 0;
}
