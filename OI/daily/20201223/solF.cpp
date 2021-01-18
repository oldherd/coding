#include <iostream>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef double db;

const db pi = acos(-1), eps = 1e-7;

db sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }

const int N = 5000010, Mod = 1000000007;
int d[N];

int qpow(int a, int b) {
	int ret = 1 % Mod;
	for(;b; b>>=1) {
		if(b&1) ret = 1ll * ret * a % Mod;
		a = 1ll * a * a % Mod;
	}
	return ret;
}

int fac[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main() {
	fac[1] = 1;
	rep(i,2,5e5) fac[i] = 1ll * fac[i-1] * i % Mod;
	int tests = read();
	rep(test,1,tests) {
		int n = read();
		if(n == 1) {
			printf("1\n");
			continue;	
		}
		int l = 2, r = 5e5;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(1ll*(mid-1)*(mid+2)/2 <= n) l = mid;
			else r = mid - 1; 
		}
		int ret = n - (l-1) * (l+2) / 2;
		const int inv2 = qpow(2, Mod - 2);
		if(ret == l) {
			printf("%lld\n", ((1ll * fac[l] * inv2)%Mod * (l + 2))%Mod);
		} else {
			if(ret == l - 1) printf("%lld\n", (1ll * fac[l+1] * inv2) % Mod);
			else {
				int t = l + 1 - ret;
				printf("%lld\n", (1ll * fac[l+1] * qpow(t, Mod - 2)) % Mod);
			}
		}
	}
	return 0;
}
