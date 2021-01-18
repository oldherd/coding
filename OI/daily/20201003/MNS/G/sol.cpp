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

int st[2][2];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    st[1][0] = 130, st[1][1] = 27 , st[0][0] = 129 , st[0][1] = 25;
    int tests;
    cin >> tests;
    while(tests--) {
        int x , y , z;
        cin >> x >> y >> z;
        if(y == st[x][0]) cout << "wan mei! ";
        else if(y < st[x][0]) cout << "duo chi yu! ";
        else cout << "ni li hai! ";

        if(z < st[x][1]) cout << "duo chi rou!\n";
        else if(z == st[x][1]) cout << "wan mei!\n";
        else cout << "shao chi rou!\n";
    }
    return 0;
}