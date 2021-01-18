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

const int N = 500010;
int a[N], b[N];
ll dis[N];
priority_queue< int, vector<int>, greater<int> > q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) cin >> a[i], ans += a[i];
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    int j = n;
    per(i,n,1) {
        while(j && b[j] >= a[i]) q.push(b[j--]);
        if(q.empty()) --k;
        else {
            dis[i] += q.top() - a[i];
            ans += dis[i];
            q.pop();
        }
    }
    sort(dis + 1, dis + n + 1, [&](int x, int y){ return x > y; });
    if(k < 0) cout << "NIE\n";
    else {
        rep(i,1,k) ans -= dis[i];
        cout << ans << endl;
    }
    return 0;
}