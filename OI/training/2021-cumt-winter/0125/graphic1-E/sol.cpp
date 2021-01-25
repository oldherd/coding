/*
  sol.cpp -- graphic1 - E - toposort & union-join
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


const int N = 20010;

struct node{
    int u, v;
}ns[N] ;

vector< vector<int> > G;

int par[N], ind[N];
int getpar(int x) { return x == par[x] ? x : x = getpar(par[x]); }

queue<int> q;

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, m, u, v;
    while(~scanf("%d %d", &n, &m)) {
        G.clear();
        G.resize(n + 1);
        memset(ind, 0, sizeof(ind));
        while(!q.empty()) q.pop();
        int tot = 0;
        rep(i,1,n) par[i] = i;
        char str[5];
        rep(i,1,m) {
            scanf("%d %s %d", &u, str, &v);
            ++u; ++v;
            if(str[0] == '=') {
                u = getpar(u); v = getpar(v);
                if(u != v) {par[u] = v;}
            } else {
                if(str[0] == '<') swap(u, v);
                ns[++tot] = node{u, v};
            }
        }
        bool ff = false;
        rep(i,1,tot) {
            u = getpar(ns[i].u); v = getpar(ns[i].v);
            if(u == v) {
                ff = true;
            }
            G[u].push_back(v); ++ind[v];
        }
        if(ff)  { puts("CONFLICT");continue; }
        int cnt = 0, nn = 0;
        bool flg = false;
        rep(i,1,n) {
            if(getpar(i) == i) {
                if(!ind[i]) q.push(i); ++nn;
            }
        }
        while(!q.empty()) {
            if(q.size() != 1) {
                flg = true;
            }
            int cur = q.front(); q.pop(); ++cnt;
            for(int ver : G[cur]) {
                if(ver != getpar(ver)) continue;
                if(--ind[ver] == 0) q.push(ver);
            }
        }
        if(cnt != nn) printf("CONFLICT\n");
        else if(flg)printf("UNCERTAIN\n");
        else printf("OK\n");
    }
    return 0;
}
