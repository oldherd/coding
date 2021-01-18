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

const int mn[] = {1 , 5 , 10};
int ans = 0;

void dfs(int lst , int left) {
    if(left <= 0) {
        ans += left == 0;
        return;
    }
    if(left >= mn[lst]) dfs(lst , left - mn[lst]);
    if(lst - 1 > -1 && left >= mn[lst - 1]) dfs(lst - 1 , left - mn[lst - 1]);
    if(lst - 2 > -1 && left >= mn[lst - 2]) dfs(lst - 2 , left - mn[lst - 2]);
}

bool chkLeap(int yr) {
    return yr % 4 == 0 && (yr % 100 != 0 || yr % 400 == 0);
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int yr;
    while(cin >> yr) {
        if(yr < 0) yr = -yr - 1;
        if(chkLeap(yr)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}