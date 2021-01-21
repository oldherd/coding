/*
  sol.cpp -- [JLOI2015]城池攻占 - leftist_tree
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
int cntCity[N], deadpls[N], a[N], root[N], f[N], c[N];
ll h[N], v[N];

vector< vector<int> > G;

struct leftist {
    int ls, rs, dis, id;
    ll tagx, tagy, hp;
} t[N];

void pushdown(int x) {
    t[t[x].ls].hp *= t[x].tagy; t[t[x].rs].hp *= t[x].tagy;
    t[t[x].ls].tagy *= t[x].tagy; t[t[x].rs].tagy *= t[x].tagy;
    t[t[x].ls].hp += t[x].tagx; t[t[x].rs].hp += t[x].tagx;
    t[t[x].ls].tagx = t[t[x].ls].tagx * t[x].tagy + t[x].tagx;
    t[t[x].rs].tagx = t[t[x].rs].tagx * t[x].tagy + t[x].tagx;
    t[x].tagy = 1; t[x].tagx = 0;
}

int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(t[x].hp > t[y].hp) swap(x, y);
    if(!t[x].tagx || t[x].tagy != 1) pushdown(x);
    if(!t[y].tagx || t[y].tagy != 1) pushdown(y);
    t[x].rs = merge(t[x].rs, y);
    if(t[t[x].ls].dis < t[t[x].rs].dis) swap(t[x].ls, t[x].rs);
    t[x].dis = t[t[x].rs].dis + 1;
    return x;
}

void del(int x) {
    if(!root[x]) return;
    if(!t[root[x]].tagx || t[root[x]].tagy != 1) pushdown(root[x]);
    root[x] = merge(t[root[x]].ls, t[root[x]].rs);
}

int stack[N], dep[N], stop = 0;
void dfs(int cur) {
    stack[++stop] = cur; dep[cur] = dep[f[cur]] + 1;
    for(int ver : G[cur]) dfs(ver);
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, m;
    scanf("%d %d", &n, &m);
    G.resize(n + 1);
    for(int i = 1; i <= n; ++i) scanf("%lld", h + i);
    ll s;
    for(int i = 2; i <= n; ++i) {
        scanf("%d %d %lld", f + i, a + i, v + i);
        G[f[i]].push_back(i);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%lld %d", &s, c + i);
        t[i].hp = s; t[i].tagy = 1; t[i].id = i;
        root[c[i]] = merge(root[c[i]], i);
    }
    dfs(1);
    for(int i = stop; i; --i) {
        int cur = stack[i];
        while(root[cur] && t[root[cur]].hp < h[i]) {
            deadpls[t[root[cur]].id] = cur;
            del(cur);
            ++cntCity[cur];
        }
        if(root[cur]) {
            if(a[i] == 1) {
                t[root[cur]].hp *= v[i];
                t[root[cur]].tagy *= v[i];
                t[root[cur]].tagx *= v[i];
            } else {
                t[root[cur]].hp += v[i];
                t[root[cur]].tagx += v[i];
            }
            root[f[cur]] = merge(root[f[cur]], root[cur]);
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d\n", cntCity[i]);
    for(int i = 1; i <= m; ++i) printf("%d\n", dep[c[i]] - dep[deadpls[i]]);
    return 0;
}
