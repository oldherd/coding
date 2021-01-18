#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef unsigned long long ll;

const int maxd = 100, ttt = 41;
ll px[maxd], fix[maxd];
int digit[maxd];

inline void readit(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

inline void readll(ll &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

int main() {
	int n, q, ai;
	ll m;
	px[0] = 1;
	for(int i = 1; i <= ttt; ++i) px[i] = px[i-1]<<1;
	readit(n);
	for(int i = 1; i <= n; ++i) {
		readit(ai);
		for(int k = ttt; ~k; --k)
			if(px[k] & ai) ++digit[k];
	}
	for(int k = 1; k <= ttt; ++k)
		fix[k] = fix[k - 1] + min(digit[k - 1], n - digit[k - 1]) * px[k - 1];
	readit(q);
	while(q--) {
		readll(m);
		if(fix[ttt] > m) {
			printf("-1\n");
			continue;
		}
		ll sum = 0, ans = 0;
		for(int k = ttt; k >= 0; --k) {
			if(sum + (n - digit[k]) * px[k] + fix[k] <= m) {
				sum += (n - digit[k]) * px[k];
				ans |= px[k];
			} else sum += digit[k] * px[k];
		}
		printf("%lld\n", ans);
	} 
	return 0;
}

