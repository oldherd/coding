#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(2);
    db x , y , ans = 0;
    rep(i,1,30) cin >> x , ans += x;
    x = ans;
    ans = 0;
    rep(i,1,10) cin >> y , ans += y;
    cout << (x + ans) * 0.025 << endl;
    return 0;
}