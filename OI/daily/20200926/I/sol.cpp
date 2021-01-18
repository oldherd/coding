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

const int N = 100010;
int pre[N][30] , num[N] , lim[30];
char str[N];

void init(int n) {
    rep(j,1,26) pre[0][j] = 0;
    rep(i,1,n) {
       rep(j,1,26) {
           if(num[i] == j) pre[i][j] = pre[i-1][j] + 1;
           else pre[i][j] = pre[i-1][j];
       }
    }
}

bool check(int l , int mid) {
    rep(j,1,26) {
        if(pre[mid][j] - pre[l-1][j] > lim[j]) return false;
    }
    return true;
}

int find(int l , int r) {
    int ll = l;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(ll , mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    scanf("%d" , &tests);
    while(tests--) {
        int n;
        scanf("%d" , &n);
        scanf("%s" , str);
        rep(i,1,26) cin >> lim[i];
        repp(i,0,n) num[i+1] = str[i] - 'a' + 1;
        init(n);
        // rep(i,1,n) {
        //     rep(j,1,26) cout << pre[i][j] << ' ';
        //     cout << endl;
        // }
        ll ans = 0;
        rep(l,1,n) {
            if(lim[num[l]] == 0) continue;
            int r = find( l , n );
            ans += r - l + 1;
            // cout << l << ',' << r << endl; 
        }
        cout << ans << endl;
    }
    return 0;
}