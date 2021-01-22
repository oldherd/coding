#include <cstdio>
#include <vector>

typedef long long ll;

using namespace std;

const int N = 300010;

int head[N], ver[N], nex[N], tot;
inline void addedge(int u, int v) {
    ver[++tot] = v; nex[tot] = head[u]; head[u] = tot;
}

int a[N], f[N];
ll h[N], v[N];

int ls[N], rs[N], dat[N];
ll dat[N], tagx[N], tagy[N];

inline void update(int x, ll mul, ll add) {
    dat[x] = dat[x] * mul + add;
    tagy[x] = tagy[x] * mul;
    tagx[x] = tagx[x] * mul + add;
}

inline void pushdown(int x) {
    update(ls[x], tagy[x], tagx[x]);
    update(rs[x], tagy[x], tagx[x]);
    tagy[x] = 1; tagx[x] = 0;
}

int merge(int x, int y) {
    if(!x || !y) return x | y;
    pushdown(x); pushdown(y);
    if(dat[x] > dat[y]) swap(x, y);
    rs[x] = merge(rs[x], y);
    if(dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
    dis[x] = dis[rs[x]] + 1;
    return x;
}



int main() {
    freopen("data.in", "r", stdin);
    freopen("data.ans", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", h + i);
    for(int i = 2; i <= n; ++i) {
        scanf("%d %d %d", f + i, a + i, v + i);
        addedge(f[i], i);
    }
    return 0;
}
