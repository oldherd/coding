#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

//const int maxn = 10000;
//int a[maxn], f[maxn], dfn[maxn], clock, thisCir, start;
//
//void dfs(int i) {
//	dfn[i] = ++clock;
//	if(dfn[a[i]]) {
//		if(a[i] == start) {
//			thisCir = clock - dfn[a[i]] + 1;
//			return;
//		} else {
//			thisCir = -1;
//			return;
//		}
//	} else {
//		dfs(a[i]);
//	}
//}
//
//int stk[maxn], top;
//
//int solve(int n) {
//	int ans = 1;
//	memset(dfn, 0, sizeof(dfn));
//	clock = top = 0;
//	for(int i = 1; i <= n; ++i)
//		if(!dfn[i]) {
//			start = i; dfs(i);
//			if(~thisCir) {
//				ans = ans * thisCir / __gcd(ans, thisCir);
//			} else return 0;
//		}
//	return ans;
//}


const int maxn = 10000010;
int a1[maxn], a2[maxn], v[maxn], m[maxn];

int main() {
//	freopen("lucky.in", "r", stdin);
//	freopen("lucky.out", "w", stdout);
//	const int limit = 20;
//	for(int n = 2; n <= limit; n += 2) {
//		for(int i = 1; i <= n; ++i) a[i] = i % 2 ? (i + n) / 2 + 1 : i / 2;
//		int ans = solve(n);
//		printf("%d\n", ans);
//	}
//	for(int i = 1; i <= 5; ++i) printf("%d ", p[i] += p[i - 1]);
//	printf("\n");
	int n;
	scanf("%d", &n); 
	for(int i = 1; i <= n * 2; ++i) {
		int t = i, cnt = 0;
		while(t % 2 == 0) ++cnt, t /= 2;
		a1[i] = cnt, a2[i] = t;
	}
	int p = n, v[1] = a[n], m[1] = a[n], ans = v[1];
	for(int i = 2; i <= n; ++i) {
		v[i] = a[n - 1 + m[i - 1]];
		m[i] = a[n - 1 + v[i - 1]];
		ans += v[i];
		if(m[i] == 1) break;
	}
	printf("%d\n", a[n]);
	return 0;
}
