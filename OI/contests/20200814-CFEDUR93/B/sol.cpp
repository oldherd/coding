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

const int maxn = 1000;
int a[maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    	int tests;
        cin >> tests;
        while(tests--) {
            string s;
            cin >> s;
            int len = s.length();
            int l = 0;
            for(l = 0; l < len && s[l] == '0'; ++l)
				;
            if(l == len) {
                cout << '0' << endl;
                continue;
            }
            int r = l, st = 0;
            while(r < len) {
                while(r + 1 < len && s[r + 1] == '1') ++r;
                a[st++] = r - l + 1;
                if(r == len - 1) break;
                l = r + 1;
                while(l + 1 < len && s[l + 1] == '0') ++l;
                if(l == len - 1) {
                    if(s[l] == '1') a[st++] = 1;
                }
                l = l + 1;
                r = l;
            }
            sort(a, a + st);
            int ans = 0;
            for(int i = st - 1; i >= 0; i -= 2) ans += a[i];
            cout << ans << endl;
        }
        
    return 0;
}
