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

const int N = 150010, SQN = 410;
int a[N], pre[SQN][SQN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, x, y;
    char op[5];
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    int s = sqrt(n);
    rep(i,1,n) rep(j,1,s) pre[j][i%j] += a[i];
    rep(q,1,m) {
        cin >> op >> x >> y;
        if(op[0] == 'A') {
            if(x <= s) {
                cout << pre[x][y] << endl;
            } else {
                int ans = 0;
                for(int i = y; i <= n; i += x) ans += a[i];
                cout << ans << endl;
            }
        } else {
            rep(j,1,s) pre[j][x%j] += y - a[x];
            a[x] = y;
        }
    }
    return 0;
}