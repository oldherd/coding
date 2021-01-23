/*
  sol2.cpp.cpp -- sol2 of jloi2015-city
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

const int N = 300010;
ll h[N], v[N];
int a[N];

int head[N], ver[N], nex[N], tot = -1;
inline void addedge(int u, int v) {
    ver[++tot] = v; nex[tot] = head[u]; head[u] = tot;
}

int ls[N], rs[N], dis[N], id[N];
ll val[N], tagadd[N], tagmul[N];
int root[N];
inline void update(int x, int ty, int tx) {
    val[x] = val[x] * ty + tx;
    tagadd[x] = tagadd[x] * ty + tx;
    tagmul[x] = tagmul[x] * ty;
}
inline void pushdown(int x) {
    update(ls[x], tagmul[x], tagadd[x]);
    update(rs[x], tagmul[x], tagadd[x]);
    tagadd[x] = 0; tagmul[x] = 1;
}
int merge(int x, int y) {
    if(!x || !y) return x | y;
    if(val[x] > val[y]) swap(x, y);
    pushdown(x); pushdown(y);
    rs[x] = merge(rs[x], y);
    if(dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
    dis[x] = dis[rs[x]] + 1;
    return x;
}
void del(int x) {
    pushdown(x);
    root[x] = merge(ls[root[x]], rs[root[x]]);
}

int city_kill[N], diepls[N], dep[N], f[N], c[N];
void dfs(int cur) {
    dep[cur] = dep[f[cur]] + 1;
    for(int i = head[cur]; ~i; i = nex[i]) {
        dfs(ver[i]);
        root[cur] = merge(root[cur], root[ver[i]]);
    }
    while(root[cur] && val[root[cur]] < h[cur]) {
        ++city_kill[cur];
        diepls[id[root[cur]]] = cur;
        del(cur);
    }
    if(root[cur]) {
        if(a[cur] == 0) {
            val[root[cur]] += v[cur];
            tagadd[root[cur]] += v[cur];
        } else {
            val[root[cur]] *= v[cur];
            tagadd[root[cur]] *= v[cur];
            tagmul[root[cur]] *= v[cur];
        }
        pushdown(cur);
    }
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    memset(head, -1, sizeof(head));
    int n, m;
    ll s;
    scanf("%d %d", &n, &m);
    rep(i,1,n) scanf("%lld", h+i);
    rep(i,2,n) {
        scanf("%d %d %lld", f + i, a + i, v + i);
        addedge(f[i], i);
    }
    rep(i,1,m) {
        scanf("%lld %d", &s, c + i);
        id[i] = i; ls[i] = rs[i] = 0; dis[i] = 1;
        val[i] = s; tagadd[i] = 0; tagmul[i] = 1;
        root[c[i]] = merge(root[c[i]], i);
    }
    dfs(1);
    rep(i,1,n) printf("%d\n", city_kill[i]);
    rep(i,1,m) printf("%d\n", dep[c[i]] - dep[diepls[i]]);
    return 0;
}
