#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000010], c[1000010];
int hh[500010], pl[1000010];
int n;

struct que{
	int l, r, ans;
}qu[500010];

int xi[500010];
inline bool cmp(int a, int b) {
	return qu[a].r < qu[b].r;
}

inline void add(int x, int w) {
	for(;x <= n; x += x&-x)
		c[x] += w;
}

inline int que(int x) {
	int ans = 0;
	for(; x; x -= x&-x)
		ans += c[x];
	return ans;
}

int main() {
	int m;
	int la = 1;
	while(~scanf("%d %d", &n, &m)) {
		memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; i++) scanf("%d", hh+i), hh[n+i] = hh[i];
	n <<= 1;
	int l, r;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &l, &r);
		qu[i].l = r; qu[i].r = l + (n >> 1);
	}
	for(int i = 0; i < m; i++) xi[i] = i;
	sort(xi, xi+m, cmp);
	for(int i = 0; i < m; i++) {
		int l = qu[xi[i]].l, r = qu[xi[i]].r;
		int num;
		for(;la <= r; la++) {
			num = hh[la];
			if(pl[num]) add(pl[num], -1), a[pl[num]]--;
			pl[num] = la;
			add(la, 1), a[la]++;
		}
		qu[xi[i]].ans = que(r) - que(l-1);
	}
	for(int i = 0; i < m; i++) printf("%d\n", qu[i].ans);
}
	return 0;
}
