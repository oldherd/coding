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

const int eps = 0.05;
int sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); 
    cout.setf(ios::fixed);
    cout.precision(1);
    db x , y , c;
    cin >> x >> y;
    c = x / (y * y);
    cout << c << endl;
    if(sign(c - 25) == 1) cout << "PANG" << endl;
    else cout << "Hai Xing" << endl;
    return 0;
}