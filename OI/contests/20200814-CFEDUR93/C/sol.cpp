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


const int maxn = 100010;
string str;
int a[maxn], s[maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        ll ans = 0;
        cin >> n;
        cin >> str;
        for(int i = 0; i < n; ++i) 
			a[i + 1] = str[i] - '0';
		s[0] = 0;
        for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
        for(int i = 1; i <= n; ++i) {
            for(int r = i; r <= i + 100 && r <= n; ++r) {
            	if(s[r] - s[i - 1] == r - i + 1) {
            		++ans;
				}
            }
        }
        cout << ans << endl;
    }
    return 0;
}
