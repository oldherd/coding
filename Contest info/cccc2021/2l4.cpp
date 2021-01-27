#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int N = 300, inf = 0x3f3f3f3f;
int mp[N][N], vis[N], a[N];

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	rep(i,0,n) rep(j,0,n) mp[i][j] = inf;
	rep(i,1,m) cin >> u >> v >> w, mp[u][v] = mp[v][u] = w;
	int k, bst = -1, theAns = inf, cnt = 0;
	cin >> k;
	rep(i,1,k) {
		int num;
		bool flg = true;
		cin >> num;
		rep(j,1,num) cin >> a[j], vis[a[j]] = i;
		int ans = mp[0][a[1]] + mp[a[num]][0];
		flg = mp[0][a[1]] != inf && mp[a[num]][0] != inf;
		if(flg)
		rep(j,1,num-1) {
			if(mp[a[j]][a[j+1]] == inf) {
				flg = false;
				break;
			}
			ans += mp[a[j]][a[j+1]];
		}
		if(num == n && flg) {
			rep(j,1,n) if(vis[j] != i) flg = false;
		} else flg = false;
		if(flg) {
//			cout << '#' << i << endl;
			++cnt;
			if(cnt == 1 || ans < theAns) bst = i, theAns = ans;
		}
	}
	cout << cnt << endl << bst << ' ' << theAns;
	return 0;
}
