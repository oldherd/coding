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

const db eps = 1e-6;
inline int sign(int x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
inline int cmp(int x , int y) { return sign(x - y); }

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int h , w , st;
        cin >> h >> w;
        st = 18 * (h - 100);
        w *= 10;
        // cout << st << " " << w << endl;
        if(abs(w - st) * 10 < st) cout << "You are wan mei!" << endl;
        else if(w > st) cout << "You are tai pang le!" << endl;
        else cout << "You are tai shou le!" << endl;
    }
    return 0;
}