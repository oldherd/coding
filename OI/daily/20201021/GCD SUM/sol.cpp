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
// int vp[N], Prime[N], low[N], phi[N], tot;
// void seive(int n) {
//     tot = 0; phi[1] = low[1] = 1;
//     rep(i,2,n) {
//         if(!vp[i]) Prime[++tot] = i, low[i] = i, phi[i] = i-1;
//         for(int j = 1; i * Prime[j] <= n && j <= tot; ++j) {
//             vp[i*Prime[j]] = 1;
//             low[i*Prime[j]] = low[i] * Prime[j];
//             if(i%Prime[j] == 0) {
//                 if(low[i] == i) phi[i*Prime[j]] = phi[i] * (Prime[j] - 1);
//                 else phi[i*Prime[j]] = phi[i/low[i]] * phi[Prime[j]*low[i]];
//                 break;
//             }
//             low[i*Prime[j]] = Prime[j];
//             phi[i*Prime[j]] = phi[Prime[j]] * phi[i];
//         }
//     }
// }

int Prime[N], phi[N], low[N], vp[N], tot;
void seive(int n) {
    phi[1] = 1; low[1] = 1;
    rep(i,2,n) {
        if(!vp[i]) Prime[++tot] = i, low[i] = i, phi[i] = i - 1;
        for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
            vp[i*Prime[j]] = 1;
            if(i % Prime[j] == 0) {
                low[i*Prime[j]] = low[i] * Prime[j];
                if(low[i] == i) phi[i*Prime[j]] = i * (Prime[j] - 1);
                else phi[i*Prime[j]] = phi[i/low[i]] * phi[Prime[j]*low[i]];
                break;
            }
            low[i*Prime[j]] = Prime[j];
            phi[i*Prime[j]] = phi[i] * phi[Prime[j]];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    ll ans = 0;
    seive(n);
    // rep(i,1,tot) cout << Prime[i] << ' '; cout << endl;
    // rep(i,1,10) cout << phi[i] << ' '; cout << endl;
    rep(i,1,n) phi[i] += phi[i-1];
    rep(k,1,n) ans += (ll)k * (2 * phi[n / k] - 1);
    cout << ans << endl;
    return 0;
}