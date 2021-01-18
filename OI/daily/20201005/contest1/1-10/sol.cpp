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
int stk[N], a[N] , top = 0;

int find(int l, int r, int x) {
    while(l < r) {
        int mid = l + r >> 1;
        if(stk[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    stk[++top] = a[1];
    rep(i,2,n) {
        if(a[i] > stk[top]) stk[++top] = a[i];
        else {
            int idx = find(1, top, a[i]);
            stk[idx] = a[i];
        }
        // rep(i,1,top) cout << a[i] << ' '; cout << endl;
    }
    cout << top << endl;
    return 0;
}