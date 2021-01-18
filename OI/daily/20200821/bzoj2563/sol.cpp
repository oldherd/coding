#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int maxn = 10010;

struct node {
    int xw, ew;
} pt[maxn];

inline int flg(int i) {
    return i % 2 ? 1 : -1;
}

inline bool cmp1(node x, node y){ return x.xw + x.ew > y.xw + y.ew; }

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &u), pt[i].xw = u << 1;
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        pt[u].ew += w; pt[v].ew += w;
    }
    sort(pt + 1, pt + n + 1, cmp1);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += flg(i) * (pt[i].xw + pt[i].ew);
    printf("%d\n", ans >> 1);
    return 0;
}