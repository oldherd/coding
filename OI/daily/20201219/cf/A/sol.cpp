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

int a[10010], b[10010];
char str[10010]; 

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        int cntA = 0, cntB = 0;
        cin >> (str + 1);
        rep(i,1,n) a[i] = str[i];
        cin >> (str + 1);
        rep(i,1,n) b[i] = str[i];
        rep(i,1,n) {
            if(a[i] > b[i]) ++cntA;
            else if(a[i] < b[i]) ++cntB;
        }
        if(cntA > cntB) cout << "RED" << endl;
        else if(cntA < cntB) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
    return 0;
}
