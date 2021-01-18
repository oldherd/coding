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

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests , x , y1 , y2;
    cin >> tests;
    while(tests--) {
        y1 = y2 = 0;
        cin >> x;
        rep(i,1,3) {
            y1 += x % 10; x /= 10;
        }
        rep(i,1,3) {
            y2 += x % 10; x /= 10;
        }
        // cout << y1 << ' ' << y2 << endl;
        if(y1 == y2) cout << "You are lucky!" << endl;
        else cout << "Wish you good luck." << endl;
    }
    return 0;
}