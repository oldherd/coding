#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;


int main() {
	int n, m;
	char str[100];
	scanf("%d %d", &n, &m);
	int base = (1<<n) - 1;
	for(int i = 1; i <= m; ++i) {
		int p=1;
		scanf("%s", str);
		for(int i = 0; i < n; ++i)
			if(str[i] == 'y') p=p<<1;
			else p=p<<1|1;
		printf("%d\n", p - base);
	}
	return 0;
}
