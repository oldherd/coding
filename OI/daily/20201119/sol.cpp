#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef long long ll;

const int N = 50010;

int a[N], buc[N];

int Prime[N], vp[N], low[N], phi[N], tot;
void seive(int n) {
	phi[1] = low[1] = 1;
	rep(i,2,n) {
		if(!vp[i]) Prime[++tot] = low[i] = i, phi[i] = i - 1;
		for(int j = 1; j < tot && i * Prime[j] <= n; ++j) {
			vp[i*Prime[j]] = 1;
			if(i % Prime[j] == 0) {
				low[i*Prime[j]] = low[i] * Prime[j];
				if(low[i] == i) phi[i*Prime[j]] = i * (Prime[j] - 1);
				else phi[i*Prime[j]] = phi[i/low[i]] * phi[low[i]*Prime[j]];
			} else {
				low[i*Prime[j]]	= Prime[j]; phi[i*Prime[j]] = phi[i] * phi[Prime[j]];
			}
		}
	}
}

int main() {
	int n, sum = 0, mx = 0;
	cin >> n;
	seive(N-10);
	cout << low[8] << ' ' << phi[8] << endl;
	rep(i,1,10) cout << phi[i] << ' '; cout << endl;
	rep(i,1,n) cin >> a[i], sum += a[i], mx = max(mx, a[i]), ++buc[a[i]];
	ll ans = 0;
	rep(d,1,n) {
		ll sgm = 0;
		for(int i = d; i <= mx; i += d) sgm += (ll)buc[i] * i;
		ans += sgm * sgm / phi[d]; 
	}
	cout << ans << endl;
	return 0;
}
