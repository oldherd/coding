/*
  sol.cpp -- LuoguP1456 Monkey King - leftist
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

const int N = 100010;
int dis[N], ls[N], rs[N], val[N], par[N];
int getpar(int x) { return par[x] == x ? x : par[x] = getpar(par[x]); }
int merge(int x, int y) {
    // printf("%d %d\n", &x, &y);
    if(!x || !y) return x | y;
    if(val[x] < val[y]) swap(x, y);
    par[y] = x;
    rs[x] = merge(rs[x], y);
    if(dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
    dis[x] = dis[rs[x]] + 1;
    return x;
}
int opr(int x) {
    par[ls[x]] = ls[x]; par[rs[x]] = rs[x];
    int r = merge(ls[x], rs[x]);
    val[x] /= 2;
    int ret = merge(x, r);
    return par[ret] = ret;
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    // freopen("offdata1.in", "r", stdin);
    // freopen("yl.out", "w", stdout);
    int n, m, x, y;
    while(~scanf("%d", &n)) {
        rep(i,1,n) scanf("%d", val + i), par[i] = i, dis[i] = 1, ls[i] = rs[i] = 0;
        scanf("%d", &m);
        rep(t,1,m) {
            scanf("%d %d", &x, &y);
            x = getpar(x); y = getpar(y);
            if(x == y) {
                printf("-1\n");
            } else {
                x = opr(x); y = opr(y);
                x = merge(x, y);
                printf("%d\n", val[x]);
            }
        }
    }
    return 0;
}
