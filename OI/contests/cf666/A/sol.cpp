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
char str[maxn];
int a[30];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; ++i) {
            scanf("%s", str);
            int len = strlen(str);
            for(int j = 0; j < len; ++j) {
                ++a[str[j] - 'a'];
            }
        }
        bool flg = true;
        for(int i = 0; i < 26; ++i)
            if(a[i] % n) {
                flg = false; break;
            }
        if(flg) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}