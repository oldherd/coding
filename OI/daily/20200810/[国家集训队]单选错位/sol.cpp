#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000010; 
int a[maxn];

int main() {
	int n, A, B, C;
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
	for (int i = 2; i <= n; i++)
		a[i] = ((long long) a[i - 1] * A + B) % 100000001;
	for (int i = 1; i <= n; i++)
		a[i] = a[i] % C + 1;
	double ans = 0;
	for(int i = 1; i <= n; ++i) {
		int pre = i == 1 ? n : i - 1;
		ans += (double)1 / max(a[pre], a[i]);
	}
	printf("%.3f\n", ans);
	return 0;
}
