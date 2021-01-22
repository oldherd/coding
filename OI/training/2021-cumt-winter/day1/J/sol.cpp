/*
  sol.cpp -- 8 digits
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <map>
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

inline int genpls(string s) {
    for(int i = 0; i < 9; ++i) if(s[i] == 'X') return i;
    return -1;
}

const int d[] = {3, -1, 1, -3};
const string ts[] = {"d", "l", "r", "u"};

queue<string> q;
map<string, string> exi;
void bfs(string s, string t) {
    while(!q.empty()) q.pop();
    q.push(s);
    exi[s] = "";
    if(s == t) return;
    while(!q.empty()) {
        string cur = q.front(); q.pop();
        int pls = genpls(cur);
        for(int i = 0; i < 4; ++i) {
            int to = pls + d[i];
            if(to > -1 && to < 9) {
                string nex(cur); swap(nex[pls], nex[to]);
                if(exi.find(nex) == exi.end()) {
                    exi[nex] = exi[cur] + ts[i];
                    q.push(nex);
                    if(nex == t) return;
                }
            }
        }
    }
}

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 1;
    cin >> tests;
    rep(test,1,tests) {
        string s, t;
        cin >> s >> t;
        bfs(s, t);
        string ans(exi[t]);
        cout << "Case " << test << ": " << ans.length() << '\n' << ans << '\n';

    }
    return 0;
}
