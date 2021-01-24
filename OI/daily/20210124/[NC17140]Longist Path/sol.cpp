/*
  sol.cpp -- NC17140 Longest Path - divide and conquer on tree + LiChao segment tree
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
// template<class T> inline T min(T x, T y) { return x < y ? x : y; }
// template<class T> inline T max(T x, T y) { return x > y ? x : y; }

template<class T>
class BIT { public:
    const int maxN;
    vector<T> c;
    BIT(int size) : maxN(size) { c.rz(size + 1); }
    void add(int x, T v) { for(; x <= maxN; x += x&(-x)) c[x] += v; }
    T qry(int x) { T ret = 0; for(; x; x -= x&(-x)) ret += c[x]; return ret; }
};

const int N = 100010;
const ll linf = 99999999999999999;

int abl[N], maxc;

struct edge {
    int x, w;
    edge(int x, int w) : x(x), w(w) {}
};
vector< vector<edge> > G;

ll k[N], b[N], ltt = 0;
ll f[N];

ll calc(int x, int id) {
    return 1ll * k[id] * x + b[id];
}

int dat[N<<2], col[N<<2], nc = 0;
inline void insert(int p, int lp, int rp, int id) {
    if(col[p] < nc) {
        dat[p] = id; col[p] = nc;
        return;
    }
    int mid = lp + rp >> 1;
    ll mval = calc(mid, id), nval = calc(mid, dat[p]);
    if(lp == rp) {
        if(calc(lp, id) > calc(lp, dat[p])) dat[p] = id;
        return;
    }
    if(k[id] < k[dat[p]]) {
        if(mval < nval) insert(p<<1, lp, mid, id);
        else insert(p<<1|1, mid + 1, rp, dat[p]), dat[p] = id;
    } else if(k[id] > k[dat[p]]) {
        if(mval < nval) insert(p<<1|1, mid+1, rp, id);
        else insert(p<<1, lp, mid, dat[p]), dat[p] = id;
    } else if(mval > nval) {
        dat[p] = id;
    }
}

ll qry(int p, int lp, int rp, int x) {
    if(col[p] < nc) return -linf;
    int mid = lp + rp >> 1;
    if(x <= mid) return max(calc(x, dat[p]), qry(p<<1, lp, mid, x));
    else return max(calc(x, dat[p]), qry(p<<1|1, mid + 1, rp, x));
}

int stk[N], siz[N], top, fa[N];
void dfs1(int cur, int pre) {
    stk[++top] = cur; siz[cur] = 1;
    fa[cur] = pre;
    for(auto e : G[cur]) {
        if(abl[e.x] && e.x != pre) {
            dfs1(e.x, cur);
            siz[cur] += siz[e.x];
        }
    }
}

int findroot(int cur) {
    top = 0;
    dfs1(cur, 0);
    if(top == 1) return cur;
    rep(i,1,top) {
        int xx = stk[i], hf = top >> 1;
        if(top - siz[xx] <= hf) {
            bool flg = true;
            for(edge e : G[xx]) {
                if(abl[e.x] && siz[e.x] > hf && e.x != fa[xx]) {
                    flg = false; break;
                }
            }
            if(flg){
                return xx;
            }
        }
    }
    return 0;
}

ll dis[N];
void dfs(int cur, int pre, int prew, ll distance) {
    stk[++top] = cur; dis[top] = distance;
    for(edge e : G[cur])
        if(abl[e.x] && e.x != pre) {
            dfs(e.x, cur, e.w, distance + 1ll * (e.w - prew) * (e.w - prew));
        }
}

void work(int cur) {
    cur = findroot(cur);
    if(top == 1) return;
    ltt = 0; ++nc;
    for(auto e : G[cur])
        if(abl[e.x]) {
            top = 0;
            dfs(e.x, cur, e.w, 0);
            ll dis1 = 1ll * e.w * e.w + qry(1, 1, maxc, e.w), md = 1;
            rep(i,1,top) {
                if(dis[md] < dis[i]) md = i;
                f[stk[i]] = max(f[stk[i]], max(dis1 + dis[i], dis[i]));
            }
            f[cur] = max(f[cur], dis[md]);
            k[++ltt] = -2 * e.w; b[ltt] = 1ll * e.w * e.w + dis[md];
            insert(1, 1, maxc, ltt);
        }
    abl[cur] = 0;
    for(auto e : G[cur])
        if(abl[e.x])
            work(e.x);
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, a, b, c;
    while(~scanf("%d", &n)) {
        G.clear();
        G.resize(n + 1);
        maxc = 0;
        memset(f, 0, sizeof(f));
        repp(i,1,n) {
            scanf("%d %d %d", &a, &b, &c);
            G[a].push_back(edge(b, c));
            G[b].push_back(edge(a, c));
            maxc = max(c, maxc);
        }
        memset(abl, 1, sizeof(abl));
        work(1);
        memset(abl, 1, sizeof(abl));
        rep(i,1,n) reverse(G[i].begin(), G[i].end());
        work(1);
        rep(i,1,n) printf("%lld\n", f[i]);
    }
    return 0;
}
