#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int maxn = 123456;
const ll limit = 100000000000005ll;
ll a[maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    ll ans = 0, t2 = 0;
    for(int i = 1; i <= n; ++i) ans += abs(a[i] - 1);
    for(int i = 1; i <= n; ++i) t2 += a[i];
    ans = min(ans, t2);
    int bs = 2;
    bool flg = true;
    int cnt = 1;
    while(flg) {
        ll tmp = 1, tans = 0;
        bool f2 = true;
        for(int i = 1; i <= n; ++i) {
            if(tmp > limit) {
                flg = false;
                break;
            }
            if(a[i] > tmp) f2 = false;
            tans += abs(a[i] - tmp);
            tmp *= bs;
        }
        if(flg) ans = min(ans, tans);
        if(f2) flg = false;
        ++bs;
    }
    printf("%lld", ans);
    return 0;
}
