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
typedef vector< vector<int> > Graph;

inline void read(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

const int maxn = 200010;

Graph G;
queue<int> q, fafafa;
deque<int> gugugu;
ll a[maxn];
int ind[maxn];

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll ans = 0;
	int n, bi;
	cin >> n;
	G.resize(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		cin >> bi;
		if(~bi) G[i].push_back(bi), ++ind[bi];
	}
	for(int i = 1; i <= n; ++i) if(!ind[i]) q.push(i);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		if(a[cur] >= 0)fafafa.push(cur);
		else gugugu.push_back(cur);
		ans += a[cur];
		for(int ver : G[cur]) {
			a[ver] += max(a[cur], 0ll);
			if(!--ind[ver]) q.push(ver);
		}
	}
	cout << ans << endl;
	while(!fafafa.empty()) cout << fafafa.front() << ' ', fafafa.pop();
	while(!gugugu.empty()) cout << gugugu.back() << ' ', gugugu.pop_back();
	cout << endl;
	return 0;
}

