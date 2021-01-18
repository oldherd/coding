#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100010, maxm = 100010;
ll wn[maxn], wm[maxn], num[maxn], dct[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lld", wn + i);
    for(int i = 1; i <= m; ++i) scanf("%lld", wm + i);
    sort(wm + 1, wm + m + 1);
    int top = 0;
    ll ans = 0;
    for(int i = 1; i <= m; ++i) {
        if(wm[i] != wm[i - 1]) wm[++top] = wm[i], num[top] = 1;
        else ++num[top];
    }
    // for(int i = 1; i <= top; ++i) printf("%lld ", wm[i]);
    // printf("\n");
    // for(int i = 1; i <= top; ++i) printf("%lld ", num[i]);
    // printf("\n");
    // for(int i = 1; i <= n; ++i) printf("%lld ", wn[i]);
    // printf("\n");
    for(int i = 1; i <= n; ++i) {
        for(int j = top; j; --j) {
            dct[j] += wn[i] / wm[j];
            wn[i] %= wm[j];
        }
    }
    // for(int i = 1; i <= top; ++i) printf("%lld ", dct[i]);
    // printf("\n");
    for(int i = 1; i <= top; ++i) {
        if(dct[i] >= num[i])  ans += num[i];
        else {
            ll maxBrw = 0;
            for(int j = top; j >= i; --j) maxBrw = maxBrw * (wm[j + 1] / wm[j]) + dct[j];
            if(maxBrw <= num[i]) {
                ans += maxBrw;
                break;
            } else {
                ans += num[i]; dct[i] -= num[i];
                for(int j = i; dct[j] < 0; ++j) {
                    ll brw = ((-dct[i]) / (wm[j + 1] / wm[j]) + 1);
                    dct[i] += brw * (wm[j + 1] / wm[j]);
                    dct[i + 1] -= brw;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}