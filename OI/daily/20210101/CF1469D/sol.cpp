#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

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

template<class T> T abs(T a) {return a > 0 ? a : -a; }

const int Mod = 1;
template<class T> Inc(T a, T b) { return (a += b) >= Mod ? a - Mod : a; }
template<class T> Dec(T a, T b) { return (a -= b) < 0 ? a + Mod : a; }
template<class T> Mul(T a, T b) { return 1ll * a * b % Mod; };

const int N = 200010, logN = 20;
struct Ans {
    int x, y;
} ans[N];
int a[N], b[logN];



int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int tests;
    cin >> tests;
    cout << tests;
    b[1] = 1; rep(i,2,6) b[i] = b[i-1] * b[i-1];
    cout << "qwq" << endl;
    cout << tests << endl;
    b[1] = 0;
    rep(test,1,tests) {
        int n;
        cin >> n;
        cout << n;
        int p = 0;
        int top = 0;
        while(b[p] < n) repp(i,b[p-1]+1,b[p]) ans[++top] = {i, b[p]}, ++p;
        rep(i,b[p-1]+1,n-1) ans[++top] = {i, n};
        per(i,p-1,1) {
            ans[++top] = {n, b[p-1]};
            repp(i,p-1,i) ans[++top] = {b[i], b[p-1]};
        }
        cout << top << endl;
        rep(i,1,top) cout << ans[i].x << ' ' << ans[i].y << endl;
    }
    return 0;
}
