#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int N = 20;
int lft[N];

struct RES {int x, y;} res[200010];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    lft[0] = 1; lft[1] = 2; rep(i,2,20) lft[i] = lft[i-1] * lft[i-1];
    while(tests--) {
        int n, tot = 0;
        cin >> n;
        int p = 1;
        while(n > lft[p]) {
            repp(i, lft[p-1] + 1, lft[p]) {
                // cout << i << ' ' << lft[p] << endl;
                res[++tot] = {i, lft[p]};
            }
            ++p;
        }
        // cout << "#####" << endl;
        repp(i,lft[p-1]+1,n) res[++tot] = {i,n};
        // cout << i << ' ' << n << endl;
        per(i,p-1,1) {
            // cout << n << ' ' << i << endl;
            res[++tot] = {n, lft[i]};
            repp(j,p-1,i) res[++tot] = {lft[j], lft[i]};
            // cout << lft[j] << ' ' << lft[i] << endl;
        }
        cout << tot << endl;
        rep(i,1,tot) cout << res[i].x << ' ' << res[i].y << endl;
    }
    return 0;
}