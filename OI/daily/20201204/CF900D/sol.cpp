#include <bits/stdc++.h>

using namespace std;

const int N = 100010, Mod = 1000000007;
inline int Inc(int x, int y) { return (x+=y) < Mod ? x : x - Mod; }
inline int Dec(int x, int y) { return (x-=y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % Mod; }
inline int Power(int x, int y) {
	int ret = 1;
	for(; y; y >>= 1) {
		if(y&1) ret = Mul(ret, x);
		x = Mul(x, x);
	}
	return ret;
}
int Prime[N], vp[N], tot;
void seive(int n) {
	for(int i = 2; i <= n; ++i) {
		if(!vp[i]) Prime[++tot] = i;
		for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
			vp[i*Prime[j]] = 1;
			if(i % Prime[j] == 0) break;
		}
	}
}

int mu(int n) {
	if(n == 1) return 1;
	int ret = 1;
	for(int i = 1, j = Prime[i]; i <= tot && 1ll * j * j <= n; j = Prime[++i]) {
		if(n % (j*j) == 0) return 0;
		if(n % j == 0) ret = -ret, n /= j;
	}
	ret = n == 1 ? ret : -ret;
	return ret < 0 ? ret + Mod : ret;
}

int main() {
	seive(N - 10);
	int x, y;
	cin >> x >> y;
	if(y % x != 0) {
		cout << 0 << endl;
		return 0;	
	}
//	cout << mu(6) << endl;
	int ans = 0, n = y / x;
	for(int i = 1; 1ll * i * i <= n; ++i) if(n % i == 0) {
		ans = Inc(ans, Mul(mu(i), Power(2, n/i-1)));
		if(i * i != n) ans = Inc(ans, Mul(mu(n/i), Power(2, i-1)));
	}
	cout << ans << endl;
	return 0;
}
