/*
  sol.cpp.cpp -- leftist as heap
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

const int inf = (1ll << 31) - 1 , N = 1000010;

int ls[ N ], rs[ N ], val[ N ], dis[ N ] , tot , root;
int merge(int x, int y) {
    if(!x || !y) return x + y;
    if( val[x] > val[y] ) swap( x , y );
    rs[ x ] = merge( rs[ x ] , y );
    if( dis[ls[x]] < dis[ rs[ x ] ] ) swap( ls[x] , rs[x] );
    dis[ x ] = dis[ rs[ x ] ] + 1;
    return x;
}


int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int tests = 1;
     rep(i,1,tests) {
        int n, op;
        scanf("%d" , &n);
        tot = 0;
        val[ root = ++tot ] = inf;
        rep(i,1,n) {
            scanf("%d" , &op);
            if( op == 1 ) {
                scanf("%d" , &val[++tot]);
                root = merge(tot , root);
             } else if( op == 2 ) {
                printf("%d\n" , val[ root ]);
             } else {
                root = merge( ls[root] , rs[root] );
             }
        }
    }
    return 0;
}
