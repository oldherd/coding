/*
  sol.cpp -- r1-f lagrange - counting
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

const int maxn = 1010;
int h[maxn], ifac[maxn];

inline int getf(int x, int k) {
    int ret = 0;
    rep(i,1,x) ret = Inc(ret, Mul(Power(i,k), Mul(i,Power(i-1,k-1))));
    return ret;
}

inline int calc(int x, int k) {
    if(x <= k + 1) return getf(x, k);
    int g = 1, par2 = 0;
    rep(i,1,k+1) g = Mul(g, x - i);
    rep(i,1,k+1) par2 = Inc(par2, Mul(Mod-1,Mul(Mul(getf(i,k),Power(x-i,Mod-2)), Mul(ifac[i-1],ifac[k+1-i]))));
    return Mul(g, par2);
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    Mod = 1e9+7;
    int n;
    ifac[0] = ifac[1] = 1;
    rep(i,2,n) ifac[i] = Mul(ifac[i-1], i), ifac[i] = Power(ifac[i],Mod-2);
    rep(i,2,n) Power(ifac[i], Mod-2);
    cout << calc(4, 2) << endl;
    while(~scanf("%d", &n)) {

    }
    return 0;
}
