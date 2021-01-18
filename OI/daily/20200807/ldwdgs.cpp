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
	x *= f;
}
const int maxn = 100010; 

double f[maxn], p[maxn];
int ind[maxn], oud[maxn];

queue<int> q;
Graph G;

int main() {
	int n, m, u, v, w;
	read(n); read(m);
	G.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		read(u); read(v); read(w);
		G[u].push_back(edge(v, w));
		++ind[v]; ++oud[u];
	}
	for(int i = 1; i <= n; ++i) if(!ind[i]) q.push(i);
	p[1] = 1;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(edge e : G[cur]) {
			p[e.x] += p[cur] / oud[cur];
			f[e.x] += (f[cur] + e.w * p[cur]) / oud[cur];
			--ind[e.x];
			if(!ind[e.x]) q.push(e.x);
		}
	}
	printf("%.2f\n", f[n]);
	return 0;
}

