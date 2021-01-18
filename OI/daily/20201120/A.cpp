#include <iostream>
#include <vector>

using namespace std;

const int N = 500010, base = 3, base2 = 23, Mod = 1000000007;

vector< vector<int> > G;

int a[N], Power[N], Power2[N], Correct[N], Correct2[N];
inline int Inc(int x, int y) { return (x+=y) >= Mod ? x - Mod : x; }
inline int Dec(int x, int y) { return (x-=y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % Mod; }
inline pair<int,int> Incer(pair<int,int> p1, pair<int,int> p2) {
	return make_pair(Inc(p1.first, p2.first), Inc(p1.second, p2.second));
}

int dfn[N], idfn[N], dep[N], top[N], fa[N], son[N], siz[N], dfs_clock;
int dat[N<<3], dat2[N<<3];
void build(int p, int lp, int rp) {
	if(lp == rp) {
		dat[p] = Power[a[idfn[lp]]]; 
		dat2[p] = Power2[a[idfn[lp]]];
		return;
	}
	int mid = lp + rp >> 1;
	build(p<<1, lp, mid); build(p<<1|1, mid+1, rp);
	dat[p] = Inc(dat[p<<1], dat[p<<1|1]);
	dat2[p] = Inc(dat2[p<<1], dat2[p<<1|1]);
}

pair<int,int> qry(int p, int lp, int rp, int ql, int qr) {
	if(lp == rp) return make_pair(dat[p], dat2[p]);
	int mid = lp + rp >> 1;
	pair<int,int> ans = make_pair(0, 0);
	if(ql <= mid) ans = qry(p<<1, lp, mid, ql, qr);
	if(qr > mid) ans = Incer(ans, qry(p<<1|1, mid+1, rp, ql, qr));
	return ans;
}

void insert(int p, int lp, int rp, int x, int v) {
	if(lp == rp) {
		dat[p] = Power[v];
		dat2[p] = Power2[v];
		return;
	}
	int mid = lp + rp >> 1;
	if(x <= mid) insert(p<<1, lp, mid, x, v);
	else insert(p<<1|1, mid+1, rp, x, v);
	dat[p] = Inc(dat[p<<1], dat[p<<1|1]);
	dat2[p] = Inc(dat2[p<<1], dat2[p<<1|1]);
}

void dfs1(int cur, int pre) {
	fa[cur] = pre; dep[cur] = dep[pre] + 1; siz[cur] = 1; son[cur] = 0;
	for(int ver : G[cur]) if(ver != pre) {
		dfs1(ver, cur);
		siz[cur] += siz[ver];
		if(!son[cur] || siz[son[cur]] < siz[ver]) son[cur] = ver;
	}
}

void dfs2(int cur, int tp) {
	dfn[cur] = ++dfs_clock; idfn[dfs_clock] = cur; top[cur] = tp;
	if(son[cur]) dfs2(son[cur], tp);
	for(int ver : G[cur]) if(ver != son[cur] && ver != fa[cur]) dfs2(ver, ver);
}


pair<int,pair<int,int>> genLCA(int x, int y, int n) {
	pair<int,int> retSecond = make_pair(0, 0);
	while(top[x] != top[y])	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		retSecond = Incer(retSecond, qry(1, 1, n, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if(dfn[x] > dfn[y]) swap(x, y);
	return make_pair(x, Incer(retSecond, qry(1, 1, n, dfn[x], dfn[y])));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Power[0] = Power2[0] = 1; Correct[0] = Correct2[0] = 0;
	for(int i = 1; i <= N - 10; ++i) Power[i] = Mul(Power[i-1], base), Power2[i] = Mul(Power2[i-1], base2), Correct[i] = Inc(Power[i], Correct[i-1]), Correct2[i] = Inc(Power2[i], Correct2[i-1]);
	int t;
	cin >> t;
	while(t--) {
		int n, q, u, v;
		cin >> n >> q;
		G.resize(n+1);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i < n; ++i) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs_clock = 0;
		dfs1(1, 0);
		dfs2(1, 1);
		build(1, 1, n);
		int tp, x, y;
		while(q--) {
			cin >> tp >> x >> y;
			if(tp == 2) {
				insert(1, 1, n, dfn[x], y);
			} else {
				pair<int,pair<int,int>> res = genLCA(x, y, n);
				int len = dep[x] + dep[y] - 2 * dep[res.first] + 1;
				if(Correct[len] == res.second.first && Correct2[len] == res.second.second) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		for(int i = 1; i <= n; ++i) dfn[i] = idfn[i] = top[i] = fa[i] = son[i] = siz[i] = 0;
		G.clear();
	}
	return 0;
}