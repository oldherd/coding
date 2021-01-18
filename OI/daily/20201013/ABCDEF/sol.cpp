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

const int N = 110;
int s[N];

map<int, int> h;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    ll ans = 0;
    cin >> n;
    rep(i,1,n) cin >> s[i];
    rep(a,1,n) rep(b,1,n) rep(c,1,n) ++h[s[a] * s[b] + s[c]];
    rep(d,1,n) rep(e,1,n) rep(f,1,n) if(s[d]) ans += h[s[d] * (s[e] + s[f])];
    cout << ans << endl;
    return 0;
}