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

const int N = 25 , S = (1<<20) + 100;

db p[N][N] , f[S];
int popCnt[S];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    rep(i,1,n) rep(j,1,n) cin >> p[i][j] , p[i][j] /= 100;
    int end = (1<<n) - 1;
    f[end] = 1;
    popCnt[0] = 0;
    rep(i,1,end) popCnt[i] = popCnt[i>>1] + (i&1);
    per(s,end-1,0) {
        rep(i,1,n) {
            int now = 1<<(i-1);
            if((~s) & now) f[s] = max(f[s] , f[s|now] * p[i][popCnt[s]+1]);
        }
    }
    cout.setf(ios::fixed);
    cout.precision(6);
    cout << f[0] * 100 << endl;
    return 0;
}