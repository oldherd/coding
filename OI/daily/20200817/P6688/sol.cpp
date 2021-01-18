#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int maxn = 1000100, base = 11, Mod = 998244353;

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}

inline int Mul(int a, int b) {
    return 1ll * a * b % Mod;
}

int a[maxn], Pow[maxn], datHash[maxn << 2], datMin[maxn << 2];
void build(int p, int lp, int rp) {
    if(lp == rp) {
        datMin[p] = a[lp];
        datHash[p] = Pow[a[lp]];
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
        datMin[p] = y;
        datHash[p] = Pow[y];
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
    pii ans(Mod, 0);
    if(l <= mid) {
        pii t = qry(p<<1, lp, mid, l, r);
        ans.first = min(ans.first, t.first);
        ans.second = Inc(ans.second, t.second);
    }
    if(r > mid) {
        pii t = qry(p<<1|1, mid + 1, rp, l, r);
        ans.first = min(ans.first, t.first);
        ans.second = Inc(ans.second, t.second);
    }
    return ans;
}

int main() {
    int n, q, op, l1, r1, l2, r2, x, y, mx = 0;
    read(n), read(q);
    for(int i = 1; i <= n; ++i) read(a[i]), mx = max(mx, a[i]);
    Pow[0] = 1;
    for(int i = 1; i <= mx; ++i) Pow[i] = Mul(Pow[i - 1], base); 
    build(1, 1, n);
    while(q--) {
        read(op);
        if(op == 0) {
            read(x); read(y);
            insert(1, 1, n, x, y);
        } else {
            read(l1); read(r1); read(l2); read(r2);
            pii range1 = qry(1, 1, n, l1, r1);
            pii range2 = qry(1, 1, n, l2, r2);  
            if(range1.first > range2.first) swap(range1, range2);
            if(Mul(range1.second, Pow[range2.first - range1.first]) == range2.second) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}