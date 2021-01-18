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

const int maxn = 1234;
int a[maxn] , ans[maxn], vis[maxn];

int find(int pre, int color , int n) {
    int mx = -1;
    for(int i = 1; i <= n; ++i)
        if(vis[i] != color) {
            if(mx == -1 || __gcd(pre, a[mx]) < __gcd(pre, a[i])) {
                mx = i;
            }
        }
    vis[mx] = color;
    return mx;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    for(int tst = 1; tst <= tests; ++tst) {
        int n , pi = -1;
        scanf("%d" , &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d" , a + i);
            if(pi == -1 || a[i] > a[pi]) pi = i;
        }
        ans[1] = a[pi]; vis[pi] = tst;
        int pre = ans[1];
        for(int i = 2; i <= n; ++i) {
            ans[i] = a[find(pre , tst , n)];
            pre = __gcd(pre , ans[i]);
        }
        for(int i = 1; i < n; ++i) printf("%d ", ans[i]);
        printf("%d\n" , ans[n]);
    }
    return 0;
}