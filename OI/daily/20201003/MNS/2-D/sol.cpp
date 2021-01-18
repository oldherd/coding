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

const int N = 2020;
int stk[N] , a[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , m , k , tmp;
    cin >> n >> m >> k;
    rep(test , 1 , k) {
        int top = 0 , now = 1;
        bool flg = true;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) {
            tmp = a[i];
            if(tmp == now) ++now;
            else stk[++top] = tmp;
            if(top > m) {
                flg = false;
                break;
            }
            while(top > 0 && stk[top] == now) ++now , --top;
        }
        if(flg && now == n + 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}