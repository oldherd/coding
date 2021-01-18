#include <cstdio>

using namespace std;

int main() {
	int n, m, tmp, a0 = 0, a1 = -1, ans = 0;
	char s[5];
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s %d", s, &tmp);
		if(s[0] == 'A') a0 &= tmp, a1 &= tmp;
		else if(s[0] == 'O') a0 |= tmp, a1 |= tmp;
		else a0 ^= tmp, a1 ^= tmp;
	}
	for(int j = 30; ~j; --j) {
		if(a0 & (1<<j)) ans += 1<<j;
		else if(m >= (1<<j) && a1 & (1<<j)) {
			m -= 1 << j;
			ans += 1 << j;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
