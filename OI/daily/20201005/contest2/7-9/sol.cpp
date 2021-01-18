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

const int N = 10010;

struct node {
    int mon, num, id;
} p[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    cin >> n;
    rep(i,1,n) {
        int k, pp, mn, sum = 0;
        cin >> k;
        rep(j,1,k) {
            cin >> pp >> mn; sum += mn;
            p[pp].mon += mn; ++p[pp].num;
        }
        p[i].mon -= sum; p[i].id = i;
    }
    sort(p+1, p+n+1, [&](node x, node y){ return x.mon > y.mon || x.mon == y.mon && x.num > y.num; });
    cout.setf(ios::fixed);
    cout.precision(2);
    rep(i,1,n) {
        cout << p[i].id << ' ' << (p[i].mon / 100.0 + 0.003) << endl;
    }
    return 0;
}