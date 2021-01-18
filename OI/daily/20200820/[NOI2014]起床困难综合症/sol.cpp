#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int op[maxn], dat[maxn];

int main() {
	int n, m;
	char opt[5];
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s %d", opt, dat + i);
		if(opt[0] == 'A') op[i] = 0;
		else if(opt[0] == 'X') op[i] = 1;
		else op[i] = 2;
	}
	int ans = 0, tot = 0;
	for(int i = 31; ~i; --i) {
		int k = 1 << i, a0 = 0, a1 = k;
		for(int j = 1; j <= n; ++j) {
			int cur = dat[j] & k;
			if(op[j] == 0) a0 &= cur, a1 &= cur;
			else if(op[j] == 1) a0 ^= cur, a1 ^= cur;
			else a0 |= cur, a1 |= cur;
		}
		if((tot | k) > m || a0 >= a1) ans |= a0;
		else tot |= k, ans |= a1;
	}
	printf("%d\n", ans);
	return 0;
}
