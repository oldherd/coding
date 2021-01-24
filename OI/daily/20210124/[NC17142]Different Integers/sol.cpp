#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200100;

int c[maxn], n;
inline void add(int x, int v) {
    for(; x <= n + 1; x += x&(-x)) c[x] += v;
}

inline int qry(int x) {
    int ret = 0;
    for(; x > 0; x -= x&(-x)) ret += c[x];
    return ret;
}

struct node {
    int li, ri, id, ans;
} qrys[maxn];

int a[maxn], nex[maxn], lst[maxn];

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int q;
    while(~scanf("%d %d", &n, &q)) {
        memset(c, 0, sizeof(c));
        memset(lst, 0, sizeof(lst));
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), a[n + i] = a[i];
        n <<= 1;
        for(int i = n; i; --i) {
            if(!lst[a[i]]) lst[a[i]] = n + 1;
            nex[i] = lst[a[i]];
            lst[a[i]] = i;
        }
        int l, r;
        for(int i = 1; i <= q; ++i) {
            scanf("%d %d", &l, &r);
            qrys[i].li = r; qrys[i].ri = l + (n>>1);
            qrys[i].id = i;
        }
        qrys[q+1].li = n + 1; qrys[q+1].id = q + 1;
        sort(qrys + 1, qrys + q + 2, [&](node &x, node &y) { return x.li > y.li; } );
        for(int i = 2; i <= q + 1; ++i) {
            for(int j = qrys[i].li; j < qrys[i-1].li; ++j) {
                add(j, 1); add(nex[j], -1);
            }
            qrys[i].ans = qry(qrys[i].ri);
        }
        sort(qrys + 1, qrys + q + 2, [&](node &x, node &y) { return x.id < y.id; } );
        for(int i = 1; i <= q; ++i) printf("%d\n", qrys[i].ans);
    }
    return 0;
}
