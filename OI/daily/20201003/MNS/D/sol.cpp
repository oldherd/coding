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
    int x , y;
    cin >> x >> y;
    cout << 5000 - 50 * (100 - x) - 50 * y << endl;
    return 0;
}