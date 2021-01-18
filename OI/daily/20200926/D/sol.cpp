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

const db eps = 1e-9;

int sign(db x) {
    return x > eps ? 1 : (x < -eps ? -1 : 0);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int a , b;
        cin >> a >> b;
        if( b *(2 * sqrt(3) + 3) / 3 <= a ) cout << "triangle" << endl;
        else if(b * 4 >= (sqrt(6) + sqrt(2)) * a) cout << "square" << endl;
        else cout << "neither" << endl;
    }
    return 0;
}