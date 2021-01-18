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

const int maxn = 10000;
int xi[maxn], yi[maxn];

int main() {
    int n, m;
    ll ans = 0;
    scanf("%d %d", &n, &m); --n; --m;
    for(int i = 1; i <= n; ++i) scanf("%d", xi + i);
    for(int i = 1; i <= m; ++i) scanf("%d", yi + i);
    sort(xi + 1, xi + n + 1);
    sort(yi + 1, yi + m + 1);
    int topn = n , topm = m;
    while(topn || topm) {
        if(!topm || (topn && xi[topn] >= yi[topm])) ans += xi[topn] * (m - topm + 1), --topn;
        else ans += yi[topm] * (n - topn + 1), --topm;
    }
    printf("%lld\n", ans);
    return 0;
}