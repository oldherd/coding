/*
  sol.cpp -- CERC2014 - Outer space invaders - dp
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
    do{ch=getchar();}while(ch<'0'||ch>'9');
    do{x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}while(ch<='9'&&ch>='0');
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
template<class T> inline void cmin(T &x, T y) { x = x > y ? y : x; }
template<class T> inline void cmax(T &x, T y) { x = x > y ? x : y; }
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


const int maxn = 310;
int a[maxn], b[maxn], d[maxn];
int ts[maxn<<1], f[maxn<<1][maxn<<1];

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int tests = 1;
    read(tests);
    rep(i,1,tests) {
        int n;
        read(n);
        rep(i,1,n) {
            read(a[i]); read(b[i]); read(d[i]);
            ts[(i<<1)-1] = a[i]; ts[i<<1] = b[i];
        }
        sort(ts+1, ts + 2*n+1);
        int ed = unique(ts+1, ts+2*n+1) - ts - 1;
        rep(i,1,n) {
            if(a[i] == b[i]) {
                int t = lower_bound(ts + 1, ts + ed + 1, a[i]) - ts;
                f[t][t] = d[i];
            }
        }
        rep(len,2,ed) {
            rep(l,1,ed-len+1) {
                int r = l + len - 1;
                int tl = ts[l], tr = ts[r];
                f[l][r] = 0;
                int md = -1;
                rep(t,1,n) if( tl <= a[t] && b[t] <= tr ) {
                    if(md == -1 || d[md] < d[t]) md = t;
                }
                if(~md) {
                    f[l][r] = 0x3f3f3f3f;
                    int kl = lower_bound(ts+1,ts+ed+1,a[md])-ts;
                    int kr = lower_bound(ts+1,ts+ed+1,b[md])-ts;
                    rep(k,kl,kr)
                        cmin(f[l][r], f[l][k-1]+f[k+1][r]+d[md]);
                }
            }
        }
        printf("%d\n", f[1][ed]);
    }
    return 0;
}
