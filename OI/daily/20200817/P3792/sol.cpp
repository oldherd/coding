#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

const int Mod = 998244353, base = 3, maxn = 500100;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}
int Pow(int a, int b) {
    long long res = 1 % Mod;
    for(; b; b >>= 1) {
        if(b&1) res = res * a % Mod;
        a = (long long)a * a % Mod;
    }
    return res;
}

int a[maxn], datMin[maxn << 2], datHash[maxn << 2];

void build(int p, int lp, int rp) {
    if(lp == rp) {
        datMin[p] = a[lp];
        datHash[p] = Pow(base, a[lp]);
        return ;
    }
    int mid = lp + rp >> 1;
    build(p<<1, lp, mid);
    build(p<<1|1, mid + 1, rp);
    datMin[p] = min(datMin[p<<1], datMin[p<<1|1]);
    datHash[p] = Inc(datHash[p<<1], datHash[p<<1|1]);
}

void insert(int p, int lp, int rp, int x, int y) {
    if(lp == rp) {
        datMin[p] = y; datHash[p] = Pow(base, y);
        return ;
    }
    int mid = lp + rp >> 1;
    if(x <= mid) insert(p<<1, lp, mid, x, y);
    else insert(p<<1|1, mid + 1, rp, x, y);
    datMin[p] = min(datMin[p<<1], datMin[p<<1|1]);
    datHash[p] = Inc(datHash[p<<1], datHash[p<<1|1]);
}

pii qry(int p, int lp, int rp, int l, int r) {
    if(l <= lp && rp <= r) {
        return pii(datMin[p], datHash[p]);
    }
    int mid = lp + rp >> 1;
    pii ans(Mod - 1, 0);
    if(l <= mid) {
        pii tmp =  qry(p<<1, lp, mid, l, r);
        ans.first = min(tmp.first, ans.first);
        ans.second = Inc(ans.second, tmp.second); 
    }
    if(r > mid) {
        pii tmp =  qry(p<<1|1, mid + 1, rp, l, r);
        ans.first = min(tmp.first, ans.first);
        ans.second = Inc(ans.second, tmp.second); 
    }
    return ans;
}

int Std[maxn];

int main() {
    int n, m, opt, x, y;
    read(n); read(m);
    for(int i = 1; i <= n; ++i) read(a[i]);
    Std[0] = 1;
    for(int i = 1; i <= n; ++i) Std[i] = Mul(Std[i - 1], base);
    for(int i = 2; i <= n; ++i) Std[i] = Inc(Std[i], Std[i-1]);
    // for(int i = 1; i <= n; ++i) cout << Std[i] << ' ';
    // cout << endl;
    build(1, 1, n);
    while(m--) {
        read(opt); read(x); read(y);
        if(opt == 1) {
            insert(1, 1, n, x, y);
        } else {
            pii range = qry(1, 1, n, x, y);
            // cout << range.first << ' ' << range.second << endl;
            // assert(range.first >= 1);
            if(range.second == Mul(Std[y - x + 1], Pow(base, range.first - 1))) {
                printf("damushen\n");
            } else {
                printf("yuanxing\n");
            }
        }
    }
    return 0;
}