/*
  sol.cpp -- model of leftist tree
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
#define leftist

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

#ifdef leftist
const int leftist_size = 100010;
template<class T> struct leftist_tree {
public:
    int ls, rs, d, f;
    bool is_del;
    T val;
};

leftist_tree<int> t[leftist_size];

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(t[x].val > t[y].val || t[x].val == t[y].val && x > y) std::swap(x, y);
    t[x].rs = merge(t[x].rs, y); t[t[x].rs].f = x;
    if(t[t[x].rs].d > t[t[x].ls].d) std::swap(t[x].ls, t[x].rs);
    t[x].d = t[t[x].rs].d + 1;
    return x;
}

int getf(int x) { return t[x].f == x ? x : (t[x].f = getf(t[x].f)); }

int del(int x) {
    t[t[x].ls].f = t[x].ls; t[t[x].rs].f = t[x].rs;
    t[x].f = merge(t[x].ls, t[x].rs);
    t[x].is_del = true;
    return t[x].val;
}
#endif

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int tests = 1;
    rep(i,1,tests) {
        int n, m, op, x, y;
        scanf("%d %d", &n, &m);
        rep(i,1,n) scanf("%d", &((t+i)->val)), t[i].f = i;
        rep(i,1,m) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d %d", &x, &y);
                if(!t[x].is_del && !t[y].is_del)
                    merge(getf(x), getf(y));
            } else {
                scanf("%d", &x);
                if(t[x].is_del) {
                    printf("-1\n");
                } else {
                    printf("%d\n", del(getf(x)));
                }
            }
        }
    }
    return 0;
}
