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

const int maxn = 350;
int a[maxn], ans[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    rep(i,1,m) cin >> a[i];
    bool flg = true;
    if(n % 2 == 0) {
        rep(i,1,m) if(a[i] > n / 2) {
            flg = false;
             break;
        }
        if(!flg) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            rep(i,1,m) {
                for(int j = i % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;
            }
            rep(i,1,n) {
                rep(j,1,m) cout << ans[i][j] << ' ';
                cout << endl;
            }
        }
    } else {
        int t[10] = {0, 0, 0};
        rep(i,1,m) {
            if(a[i] > n / 2 + 1) {
                flg = false;
                break;
            }
            if(a[i] == n / 2 + 1) t[i%2] = 1;
        }
        if(t[0] && t[1]) flg = false;
        if(!flg) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            rep(i,1,m) {
                if(t[1]) for(int j = (i+1) % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;
                else for(int j = i % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;
            }
            rep(i,1,n) {
                rep(j,1,m) cout << ans[i][j] << ' ';
                cout << endl;
            }
        }

    }
    return 0;
}