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

const int Mod = 1000000007;
inline int Inc(int x, int y) { return (x+=y)>=Mod?x-Mod:x; }
inline int Dec(int x, int y) { return (x-=y)<0?x+Mod:x; }
inline int Mul(int x, int y) { return (int)((ll)x * y % Mod); }

const int N = 510, K = 510;
int a[N], f[N][K];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) {
        f[i][0] = 1;
        int ls, rs;
        for(ls = i; ls > 1 && a[ls-1] < a[i]; --ls);
        fpr(rs = i; rs < n && a[rs+1] < a[i]; ++rs);
        rep(j,1,m) {
            f[i][j] += f[i-1][j-1];
            
        }
    }
    return 0;
}