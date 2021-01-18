#include <bits/stdc++.h>

using namespace std;

const int Mod = 1000000007, inv6 = 166666668;
inline int Inc(int x, int y) { return (x += y) < Mod ? x : x - Mod; }
inline int Dec(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % Mod; }
//inline int Power(int a, int b) {
//	int ret = 1 % Mod;
//	for(; b; b >>= 1) {
//		if(b % 2) ret = 1ll * ret * a % Mod;
//		a = 1ll * a * a % Mod;	
//	}
//	return ret;
//}

inline int genS1(int l, int r) { return (1ll*(l+r)*(r-l+1)) % Mod; }
inline int genS2Mid(int n) { return Mul(Mul(Mul(n,n+1),(2*n+1)%Mod), inv6); }
inline int genS2(int l, int r) { return Dec(genS2Mid(r), genS2Mid(l)); }

int Diver1(int n, int ll, int rr) {
	int ret = 0;
	for(int l = ll, r; l <= rr; l = r + 1) {
		r = min(n/(n/l), rr);
		ret += Mul(n/l, genS1(l, r));
	}
	return ret;
}

int Diver2(int m, int n, int ll, int rr) {
	int ret = 0;
	for(int l = ll, r; l <= rr; l = r + 1) {
		r = min(min(n/(n/l), m/(m/l)), rr);
		ret += Mul(n/l, Mul(m/l, genS2(l, r)));
	}
	return ret;
}

int main() {
	int n, m;
//	cout << Power(2, 1) << endl;
//	cout << Power(6, Mod - 2) << ' ' << Mul(6, Power(6, Mod - 2));
	cin >> n >> m; if(n > m) swap(n, m);
	int ans = Dec(Mul(Dec(genS1(1,n),Diver1(n,1,n)),Dec(genS1(1,m),Diver1(m,1,m))), Inc(Dec(Mul(Mul(n,m),n),Inc(Mul(n,Diver1(m,1,n)),Mul(m,Diver1(n,1,n)))),Diver2(n,m,1,n)));
	cout << ans << endl;
//	int a2 = 0;
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	for(int i = 1; i <= n; ++i) t1 += n/i*i, t3 = m/i*i, t4 = (n/i)*(m/i)*i*i;
	for(int i = 1; i <= m; ++i) t2 += m/i*i;
	cout << (n*(n+1)/2-t1) * (m*(m+1)/2-t2) - (m*n*n - m*t1-n*t3 + t4) << endl;
	return 0;
}
