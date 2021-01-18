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

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
db mon;
while(cin >> mon) {
    mon *= 10;
    int m = (int)(mon + 0.5);//四舍五入
    ans = 0;
    dfs(2 , m);
    cout << ans << endl;
 
}
    return 0;
}