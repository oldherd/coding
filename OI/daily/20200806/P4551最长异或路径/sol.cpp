#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(b);i>=(a);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

struct edge {
	int x, w;
	edge() {}
	edge(int x, int w): x(x), w(w) {}
};

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<edge> > Graph;

inline void read(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
}

const int maxn = 100010, maxs = 40 * maxn, MDP = 1 << 30;

Graph g;	

int trie[maxs][2], tot = 2;

void insert(int cur) {
	int p = 1;
	for(int i = MDP; i; i >>= 1) {
		bool tar = i & cur;
		if(!trie[p][tar]) trie[p][tar] = tot++;
		p = trie[p][tar];
	}
}

int find(int cur) {
	int p = 1, ret = 0;
	for(int i = MDP; i; i >>= 1) {
		bool tar = !(bool)(cur & i);
		if(trie[p][tar]) {
			ret = (ret << 1) | (int)tar;
			p = trie[p][tar];
		} else {
			ret = (ret << 1) | (int)!tar;
			p = trie[p][!tar];
		}
	}
	return ret;
}

int xsum[maxn]; 
void dfs(int pre, int cur) {
	for(edge e : g[cur])
		if(e.x != pre) {
			xsum[e.x] = xsum[cur] ^ e.w;
			insert(xsum[e.x]);
			dfs(cur, e.x);
		}
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n, u, v, w;
	read(n);	
	g.resize(n + 1);
	for(int i = 1; i < n; ++i) {
		read(u); read(v); read(w);
		g[u].push_back(edge(v, w));
		g[v].push_back(edge(u, w));
	}
	srand((unsigned)time(NULL));
	int root = (ll)rand() * rand() % n + 1;
	dfs(0, root);
	insert(0);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, xsum[i] ^ find(xsum[i]));
	printf("%d\n", ans);
	return 0;
}

