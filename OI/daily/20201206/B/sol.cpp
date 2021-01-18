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

int a[20], cnt[10000];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int ans = 0;
    bool flg = false;
    rep(i,1,14) cin >> a[i], ++cnt[a[i]];
    rep(i,1,13) {
        if(!cnt[i]) ++ans;
        else if(cnt[i] >= 2) flg = true;
    }
    if(!flg) ++ans;
    cout << ans << endl;
    return 0;
}