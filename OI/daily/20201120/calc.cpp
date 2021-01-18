#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NN = 50000010;

int Prime[NN], vp[NN], minFac[NN], tot;
void seive(int n) {
	for(int i = 2; i <= n; ++i) {
		if(!vp[i]) Prime[++tot] = i, minFac[i] = i;
		for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
			vp[i*Prime[j]] = 1, minFac[i] = Prime[j];
			if(i % Prime[j] == 0) break;
		}
	}
}

const ll N = 870699338, sqn = sqrt(N); 

__int128 power(__int128 a, __int128 b) {
	__int128 res = 1;
	for(; b; b >>= 1) {
		if(b&1) res = res * a;
		a = a * a;
	}
	return res;
}

int main() {
	seive(NN - 10);
	ll nn;
	__int128 ans = 1;
	cin >> nn;
	__int128 n = nn;
	for(int i = 1; i <= tot; ++i) {
		if(n % Prime[i]) continue;
		int cnt = 0;
		while(n % Prime[i] == 0) n /= Prime[i], ++cnt;
		ans = ans * (power(Prime[i], cnt+1) - 1) / (Prime[i]-1); 
	}
	if(n > 1) ans = ans * (1 + n + n * n);
	cout << (ll)ans << endl;
	return 0;
}
