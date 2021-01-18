#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define rep(i,a,b) for(int i = (a) ; i <= (b) ; ++i)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; --i)
#define repp(i,a,b) for(int i = (a) ; i < (b) ; ++i)
#define perr(i,a,b) for(int i = (a) ; i > (b) ; --i)
#define int long long

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> VI;

const int N = 100010 , M = 1000100;

int Prime[N] , vp[N] , tot;
void seive(int n) {
	tot = 0;
	for(int i = 2; i <= n; ++i) {
		if(!vp[i]) Prime[++tot] = i;
		for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
			vp[i * Prime[j]] = 1;
			if(!(i%Prime[j])) break;
		}
	}
}

int quq[M] , lrPrime[M];

signed main() {
	seive(sqrt(10.0 + 2147483647));
	int l , r;
	while(~scanf("%lld %lld" , &l , &r)) {
		int top = 0;
		memset(quq , 0 , sizeof(quq));
		if(l == 1) quq[1] = 1;
		rep(j,1,tot) {
			ll tl = ((ll)l + Prime[j] - 1) / Prime[j];
			for(int i = max(tl , 2ll); (ll)i * Prime[j] <= r; ++i)
				quq[i * Prime[j] - l + 1] = 1;
		}
		rep(i,l,r) if(!quq[i-l+1]) lrPrime[++top] = i;
		if(top > 1) {
			int mi = 1 , mx = 1;
			rep(i,2,top-1) {
				int dis = lrPrime[i+1] - lrPrime[i];
				if(dis > lrPrime[mx+1] - lrPrime[mx]) mx = i;
				if(dis < lrPrime[mi+1] - lrPrime[mi]) mi = i;
			}
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n" , lrPrime[mi] , lrPrime[mi+1] , lrPrime[mx] , lrPrime[mx + 1]);
		} else {
			printf("There are no adjacent primes.\n"); 
		} 
		
	}
	return 0;	
}