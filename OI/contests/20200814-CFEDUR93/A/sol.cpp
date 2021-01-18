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

const int maxn = 50100;
int a[maxn];

int bound(int l, int r, int x) {
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(a[x] < mid) l = mid;
        else r = mid - 1;
    }
    return r;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        bool flg = false;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        if(a[1] + a[2] <= a[n]) {
        	cout << 1 << ' ' << 2 << ' ' << n << endl;
        } else {
        	cout << "-1" << endl;
        }
    }    
    return 0;
}
