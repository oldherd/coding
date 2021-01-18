#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef unsigned long long ull;

vector< vector<int> > G;

const int N = 110;
int col[N], c[2] = {0, 0};

void dfs(int cur, int pre, int color) {
    col[cur] = color; ++c[color];
    for(int ver : G[cur])
        if(pre != ver)
            dfs(ver, cur, color ^ 1);
}

ull ans[N];
int note[N];

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, ui, vi;
    cin >> n;
    G.resize(n + 1);
    rep(i,1,n-1) {
        cin >> ui >> vi;
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    dfs(1, 0, 0);
    int mi = c[1] < c[0];
    int cnt = 2;
    rep(i,1,n) if(col[i] == mi) {
        note[i] = cnt;
        ans[i] = (1ull << 60) - 1;
        ans[i] -= (1ull << cnt++);
        ans[i] -= 1;
    }
    rep(i,1,n) if(col[i] == (mi ^ 1)) {
        ans[i] |= 1;
        for(int ver : G[i]) ans[i] |= (1ull<<note[ver]);
    }
    rep(i,1,n) cout << ans[i] << ' ';
    return 0;
}
