#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(b);i>=(a);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef vector< vector<int> > Graph;


struct node {
	int x, y;
	node() {}
	node(int x, int y):x(x), y(y) {}
	bool operator < (const node& o) const {
		return x < o.x || x == o.x && y < o.y;
	}
};

const int maxn = 500010;
Graph G;
map<node, int> mp;
int a[maxn], id[maxn];

int main() {
	int n, m, u, v;
	ll ans = 0;
	scanf("%d %d", &n, &m);
	G.resize(n + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), id[i] = i;
	sort(id + 1, id + n + 1, [&](int x, int y){ return a[x] < a[y] || a[x] == a[y] && x < y; });
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		int x = id[i];
		sort(G[x].begin(), G[x].end(), [&](int x, int y){ return a[x] < a[y] || a[x] == a[y] && x < y; });
		int sz = G[x].size();
		for(int i = 0; i < sz / 2 + 1; ++i) {
			int ver = G[x][i];
			node edge(min(x, ver), max(x, ver));
			if(mp.find(edge) == mp.end()) {
				mp[edge] = min(a[x], m);
				ans += min(a[x], m);
			}
		}
		for(int i = sz / 2 + 1; i < sz; ++i) {
			int ver = G[x][i];
			node edge(min(x, ver), max(x, ver));
			if((a[ver] < a[x] || a[ver] == a[x] && ver < x) && mp.find(edge) == mp.end()) {
				mp[edge] = m;
				ans += m;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

