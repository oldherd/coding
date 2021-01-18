#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(b);i>=(a);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<int> > Graph;

const ll p = 998244353;
const int maxn = 100010; 

Graph G, _G;
queue<int> q;
int ind[maxn], _ind[maxn];
ll cnt[maxn], _cnt[maxn];

inline ll inv(ll a) {
	ll res = 1 % p;
	for(int b = p - 2; b; b >>= 1) {
		if(b & 1) res = res * a % p;
		a = a * a % p;		
	}
	return res;
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	G.resize(n + 1);
	_G.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		G[u].push_back(v); ++ind[v];
		_G[v].push_back(u); ++_ind[u];
	}
	for(int i = 1; i <= n; ++i) if(!ind[i]) q.push(i);
	ll tot = 0, ans = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		tot = (tot + cnt[cur]) % p;
		for(int ver : G[cur]) {
			cnt[ver] = (cnt[ver] + cnt[cur] + 1) % p;
			if(!(--ind[ver])) q.push(ver);
		}
	}
	for(int i = 1; i <= n; ++i) if(!_ind[i]) q.push(i);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int ver : _G[cur]) {
			_cnt[ver] = (_cnt[ver] + _cnt[cur] + 1) % p;
			if(!(--_ind[ver])) q.push(ver);
		}
	}
	tot = (tot + n) % p; 
	for(int cur = 1; cur <= n; ++cur)
		for(int ver : G[cur])
			ans = (ans + ((cnt[cur] + 1) * (_cnt[ver] + 1)) % p) % p;
	ans = ans * inv(tot) % p;
	cout << ans << endl;
	return 0;
}
