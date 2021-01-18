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
ll f[N];
int Prime[N], vp[N], mu[N], low[N], tot;
void seive(int n) {
    tot = 0; mu[1] = low[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(!vp[i]) Prime[++tot] = i, low[i] = i, mu[i] = -1;
        for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
            vp[i*Prime[j]] = 1;
            if(i % Prime[j] == 0) {
                low[i*Prime[j]] = low[i] * Prime[j];
                if(low[i] == i) mu[i*Prime[j]] = 0;
                else mu[i*Prime[j]] = mu[i/low[i]] * mu[Prime[j]*low[i]];
                break;
            } else {
                low[i*Prime[j]] = Prime[j];
                mu[i*Prime[j]] = mu[i] * mu[Prime[j]];
            }
        }
    }
    for(int j = 1; j <= tot; ++j) for(int i = 1; j <= tot && i * Prime[j] <= n; ++i) f[i*Prime[j]] += mu[i];
    for(int i = 1; i <= n; ++i) f[i] += f[i-1];
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    ll ans = 0;
    cin >> n;
    seive(n);
    rep(i,1,n) mu[i] += mu[i-1];
    for(int l = 1, r; l <= n; l = r + 1) {
        r = min(n, n/(n/l));
        ans += 1ll * (mu[r] - mu[l-1]) * (n / l) * (n / l);
    }
    cout << ans << endl;
    return 0;
}