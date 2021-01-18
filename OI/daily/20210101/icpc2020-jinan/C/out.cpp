"#include <cstdio>" \n
"#include <cmath>" \n
"#include <cstring>" \n
"#include <cstdlib>" \n
"#include <iostream>" \n
"#include <algorithm>" \n
"#include <queue>" \n
"#include <vector>" \n
"#define rep(i,a,b) for(int i=(a);i<=(b);++i)" \n
"#define per(i,a,b) for(int i=(a);i>=(b);--i)" \n
"#define repp(i,a,b) for(int i=(a);i<(b);++i)" \n
"#define perr(i,a,b) for(int i=(a);i>(b);--i)" \n
"#define pb push_back" \n
"#define rz resize" \n
"" \n
"using namespace std;" \n
"" \n
"typedef long long ll;" \n
"typedef unsigned long long ull;" \n
"typedef double db;" \n
"typedef long double ldb;" \n
"typedef vector<int> VI;" \n
"typedef vector<ll> VL;" \n
"typedef vector<ldb> VD;" \n
"" \n
"const int Mod = 1;" \n
"inline int Inc(int x, int y) { return (x += y) < Mod ? x : x - Mod; }" \n
"inline int Dec(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }" \n
"inline int Mul(int x, int y) { return 1ll * x * y % Mod; }" \n
"" \n
"template<class T> inline T abs(T x) { return x > 0 ? x : -x; }" \n
"template<class T> inline T cmin(T &x, T &y) { x = x > y ? y : x; }" \n
"template<class T> inline T cmax(T &x, T &y) { x = x > y ? x : y; }" \n
"template<class T> inline T min(T x, T y) { return x < y ? x : y; }" \n
"template<class T> inline T max(T x, T y) { return x > y ? x : y; }" \n
"" \n
"template<class T>" \n
"class BIT { public:" \n
"    const int maxN;" \n
"    vector<T> c;" \n
"    BIT(int size) : maxN(size) { c.rz(size + 1); }" \n
"    void add(int x, T v) { for(; x <= maxN; x += x&(-x)) c[x] += v; }" \n
"    T qry(int x) { T ret = 0; for(; x; x -= x&(-x)) ret += c[x]; return ret; }" \n
"};" \n
"" \n
"int main() {" \n
"    if(fopen("yl.in", "r")) {" \n
"        freopen("yl.in", "r", stdin);" \n
"        freopen("yl.out", "w", stdout);" \n
"    }" \n
"    int tests = 1;" \n
"    rep(i,1,tests) {" \n
"" \n
"    }" \n
"    return 0;" \n
"}" \n
