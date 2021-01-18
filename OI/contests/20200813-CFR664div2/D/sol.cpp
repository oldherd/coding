#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;

const int maxn = 100010;
int a[maxn];
ll s[maxn];

int main() {
    int n, d, m;
    cin >> n >> d >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll ans = 0, tmp = 0;
    if(a[n] <= m) {
        for(int i = 1; i <= n; ++i) ans += a[i];
        cout << ans << endl;
        return 0;
    }
    s[1] = a[1]; for(int i = 2; i <= n; ++i) s[i] = s[i - 1] + a[i];
    int t = upper_bound(a + 1, a + n + 1, m) - a;
	ans = s[t - 1];
    int ed = n / (d + 1) + ((n % (d + 1)) ? 1 : 0);
    for(int k = 1; k <= ed && k <= n - t + 1; ++k) {
        tmp = s[n] - s[n - k];
        int lft = (n - 1) - (k - 1) * (d + 1);
        if(lft > 0) tmp += s[t - 1] - s[max(t - lft - 1, 0)];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
