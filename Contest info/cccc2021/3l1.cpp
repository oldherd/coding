#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int N = 1100;
vector< vector<int> > g;
int ind[N], outd[N], f[N], vis[N];

void dfs(int s) {
	for(int ver : g[s]) if(!vis[ver]) {
		vis[ver] = 1;
		dfs(ver);
	}
}

queue<int> q;
void topo(int n) {
	rep(i,1,n) if(vis[i] && !ind[i]) q.push(i);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int ver : g[cur]) if(vis[ver]) {
			if(--ind[ver] == 0) q.push(ver);
			f[ver] += f[cur];
		}
	}
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	g.resize(n+1);
	rep(i,1,m) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	int s, t;
	cin >> s >> t;
	vis[s] = 1;
	dfs(s);
	f[s] = 1;
	rep(i,1,n) if(vis[i]) {
		for(int ver:g[i]) if(vis[ver]) {
			++ind[ver]; ++outd[i];
		}
	}
	topo(n);
	int cnt = 0;
	rep(i,1,n)
	if(outd[i] == 0) {
		if(f[i]) ++cnt;
	}
	cout << f[t] << ' ';
	if(cnt <= 1) cout << "Yes";
	else cout << "No";
	return 0;
}
