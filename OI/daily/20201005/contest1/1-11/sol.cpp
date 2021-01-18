#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int K = 15 , N = 10010;

int sco[K];
db ans[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , m , k;
    cin >> n >> k >> m;
    rep(i,1,n) {
        ll tmp = 0;
        rep(j,1,k) cin >> sco[j];
        sort(sco + 1 , sco + k + 1);
        rep(j,2,k-1) tmp += sco[j];
        ans[i] = (db)tmp / (k-2);
    }
    sort(ans + 1 , ans + n + 1);
    cout.setf(ios::fixed);
    cout.precision(3);
    rep(i,1,m-1)
        cout << ans[n-m+i] << ' ';
    cout << ans[n];
    return 0;
}