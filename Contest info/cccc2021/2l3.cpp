#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int N = 100;
int a[N], node[N];
int stk[N], top = 0;
int stk2[N], top2 = 0;

void dfs(int p, int n) {
	if((p<<1)<=n) dfs(p<<1, n);
	if((p<<1|1) <= n) dfs(p<<1|1, n);
	stk[++top] = p;
}

void dfs2(int p, int n) {
	if((p<<1)<=n) dfs2(p<<1, n);
	stk2[++top2] = p;
	if((p<<1|1) <= n) dfs2(p<<1|1, n);
}

queue<int> q;
void bfs(int start, int n) {
	q.push(start);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		stk2[++top2] = cur;
		if((cur<<1)<=n) q.push(cur<<1);
		if((cur<<1|1)<=n) q.push(cur<<1|1);	
	}
}

int main() {
	int n, tmp;
	cin >> n;
	dfs(1, n);
	rep(i,1,n) {
		cin >> tmp;
		a[stk[i]] = tmp;
	}
	bfs(1, n);
	rep(i,1,n-1) cout << a[stk2[i]] << ' ';
	cout << a[stk2[n]];
	return 0;
}
