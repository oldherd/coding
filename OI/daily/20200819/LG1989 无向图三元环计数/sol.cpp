#include <cstdio>
#include <vector>

using namespace std;

typedef vector< vector<int> > Graph;
Graph G;

const int maxn = 100010;
int vis[maxn];

int main() {
	int n, m, u, v;
	scanf("%d %d", &n, &m);
	G.resize(n + 1);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j : G[i])
			if(G[i].size() > G[j].size() || G[i].size() == G[j].size() && i > j) vis[j] = i;
		for(int j : G[i])
			if(G[i].size() > G[j].size() || G[i].size() == G[j].size() && i > j)
				for(int k : G[j])
					if(G[j].size() > G[k].size() || G[j].size() == G[k].size() && j > k)
						if(vis[k] == i)
							++ans;
	}
	printf("%d\n", ans);
	return 0;	
}
