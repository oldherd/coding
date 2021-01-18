#include <cstdio>
#include <cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;

const int M = 1000100 , inf = 0x7f7f7f7f;
int a[M];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    scanf("%d" , &tests);
    rep(test,1,tests) {
        int n , m , k;
        scanf("%d %d %d" , &n , &m , &k);
        int mi = 0; a[0] = inf;
        rep(i,1,m) {
            scanf("%d" , a + i);
            if(a[i] < a[mi]) mi = i;
        }
        ll ans = k - 1;
        rep(i,1,m)
            if(i != mi) {
                ans += abs(k - a[i]) << 1;
            } else {
                ans += abs(k - a[i]) + abs(a[i] - 1);
            }
        printf("%lld\n" , ans);
    }
    return 0;
}