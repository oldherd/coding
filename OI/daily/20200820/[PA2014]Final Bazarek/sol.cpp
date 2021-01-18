#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
int a[maxn];
ll s[maxn], lodd[maxn], leven[maxn], rodd[maxn], reven[maxn];

int main() {
    int n, m, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1, [&](int x, int y){ return x > y; });
    s[0] = 0; lodd[0] = leven[0] = -1;
    for(int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
        if(a[i] % 2) lodd[i] = a[i], leven[i] = leven[i-1];
        else lodd[i] = lodd[i-1], leven[i] = a[i];
    }
    rodd[n + 1] = reven[n + 1] = -1;
    for(int i = n; i; --i) {
        if(a[i] % 2) rodd[i] = a[i], reven[i] = reven[i + 1];
        else reven[i] = a[i], rodd[i] = rodd[i + 1];
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &k);
        if(s[k] % 2) {
            printf("%lld\n", s[k]);
        } else {
            ll ans = -1;
            if(~lodd[k] && ~reven[k + 1]) {
                ans = max(ans, s[k] - lodd[k] + reven[k + 1]);
            }
            if(~leven[k] && ~rodd[k + 1]) {
                ans = max(ans, s[k] - leven[k] + rodd[k + 1]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}