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

const int N = 50010, NN = 50000;
int Prime[N], vp[N], low[N], mu[N], tot;
void seive(int n) {
    mu[1] = low[1] = 1;
    rep(i,2,n) {
        if(!vp[i]) Prime[++tot] = i, low[i] = i, mu[i] = -1;
        for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
            vp[i*Prime[j]] = 1;
            if(i%Prime[j] == 0) {
                low[i*Prime[j]] = low[i] * Prime[j];
                if(low[i] == i) mu[i*Prime[j]] = 0;
                else mu[i*Prime[j]] = mu[i/low[i]] * mu[low[i]*Prime[j]];
                break;
            }
            low[i*Prime[j]] = Prime[j];
            mu[i*Prime[j]] = -mu[i]; 
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    seive(NN);
    rep(i,1,NN) mu[i] += mu[i-1];
    int tests;
    cin >> tests;
    rep(test,1,tests) {
        int a, b, d, mn;
        cin >> a >> b >> d;
        a /= d; b /= d; mn = min(a, b);
        ll ans = 0;
        for(int l = 1, r; l <= mn; l = r + 1) {
            r = min(mn, min(a/(a/l), b/(b/l)));
            ans += 1ll * (mu[r]-mu[l-1]) * (a/l) * (b/l);
        }
        cout << ans << endl;
    }
    return 0;
}