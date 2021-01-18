#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

ull gen(ull p) {
    if(p % 4 == 3) return 0;
    if(p % 4 == 0) return p;
    if(p % 4 == 1) return (p - 1) ^ p;
    return p ^ (p - 1) ^ (p - 2);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        ull l, r, s, al, ar;
        ull ans = 0;
        scanf("%llu %llu %llu", &l, &r, &s);
        if(r - l + 1 <= 8) {
            for(ull i = l; i <= r; ++i)
                for(ull j = i; j <= r; ++j) {
                    if((gen(j) ^ gen(i - 1)) <= s) ans = max(ans, j - i + 1);
                }
            if(ans) printf("%llu\n", ans);
            else printf("-1\n");
        } else {
            al = l;
            while(al % 4) ++al;
            ar = r;
            while(ar % 4 != 3) --ar;
            ans = ar - al + 1;
            for(ull i = l; i <= al; ++i)
                for(ull j = ar; j <= r; ++j) {
                    if((gen(i - 1) ^ gen(j)) <= s) ans = max(ans, j - i + 1);
                }
            printf("%llu\n", ans);
        }
    }
    return 0;
}