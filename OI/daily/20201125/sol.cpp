#include <bits/stdc++.h>

using namespace std;

const int Mod = 20101009;
inline int Inc(int x, int y) { return (x+=y) < Mod ? x : x - Mod; }
inline int Dec(int x, int y) { return (x-=y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % Mod; }
inline int fix(int x) { return x < 0 ? Mod + x : x; }

const int N = 10000010;

int Prime[N], vp[N], low[N], mu[N], sgm[N], tot;
void seive(int n) {
	mu[1] = low[1] = 1;
	for(int i = 2; i <= n; ++i) {
		if(!vp[i]) Prime[++tot] = i, low[i] = i, mu[i] = -1;
		for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
			vp[i*Prime[j]] = 1;
			if(i % Prime[j] == 0) {
				low[i*Prime[j]] = low[i] * Prime[j];
				if(low[i] == i) mu[i*Prime[j]] = 0;
				else mu[i*Prime[j]] = mu[i/low[i]] * mu[low[i]*Prime[j]];
				break;
			} else {
				low[i*Prime[j]] = Prime[j];
				mu[i*Prime[j]] = -mu[i];
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; j += i)
			sgm[j] = Inc(Mul(fix(mu[i]), i), sgm[j]);
}

inline int sum(int x, int y) { return (1ll * (x + y) * (y - x + 1) / 2) % Mod; }

int main() {
	seive(N - 10);
//	for(int i = 1; i <= 20; ++i) cout << Prime[i] << ' '; cout << endl;
//	for(int i = 1; i <= 20; ++i) cout << mu[i] << ' '; cout << endl;
	int n, m, N;
	cin >> n >> m;
	N = min(n, m);
	int ans = 0;
	for(int i = 1; i <= N; ++i) {
		ans = Inc(ans, Mul(i, Mul(sgm[i], Mul(sum(1, n/i), sum(1, m/i)))));
	}
	cout << ans << endl;
	return 0;
}
