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

const int maxn = 100, p = 998244353;
int a[maxn], rnk[maxn], n;
ll fac[maxn];

ll inv(ll a) {
	ll res = 1 % p;
	ll b = p - 2;
	for(; b; b >>= 1) {
		if(b & 1) res = res * a % p;
		a = a * a % p;
	}
	return res;
}

ll C(int n, int m) {
	if(n < m) return 0;
	if(n == m) return 1;
	return (fac[n] * inv(fac[n - m]) % p) * inv(fac[m]) % p;
}

ll P(int k, int t) {
	if(k < t) return 0;
	if(k == t) return inv(C(n - 1, t));
	return C(n - 1 - t, k - t) * inv(C(n - 1, k)) % p;
}

ll solve(int cur) {
	int l = cur - 1, r = cur + 1;
	while(l > 0 && a[l] < a[cur]) --l;
	while(r <= n && a[r] < a[cur]) ++r;
	if(l == 0 && r == n + 1) return n - 1;
	ll ans = 0;
	for(int k = 1; k < n; ++k) {
		ll ans1 = 0, ans2 = 0, ans3 = 0;
		if(l > 0) ans1 = P(k, cur - l);
		if(r <= n) ans2 = P(k, r - cur);
		if(l > 0 && r <= n) ans3 = P(k, r - l);	
		ans += 1 - ans1 - ans2 + ans3;
	}
	return (ans % p + p) % p;
}

int main() {
	cin >> n;
	fac[1] = 1;
	for(int i = 2; i <= 60; ++i) fac[i] = fac[i - 1] * i % p;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cout << solve(i) << ' ';
	cout << endl;
	return 0;
}
