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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        if(n == 1) cout << "No" << endl;
        else if(n == 2) cout << "Yes" << endl;
        else {
            bool flg = true;
            int sqr = min((int)sqrt(n) + 1 , n - 1);
            rep(i,2,sqr) {
                if(n % i == 0) flg = false;
            }
            if(flg) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}