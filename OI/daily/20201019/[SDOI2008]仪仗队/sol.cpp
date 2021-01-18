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

const int N = 40010;

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
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    seive(n-1);
    ll ans = 0; 
    rep(i,1,n-1) ans += phi[i];
    cout << (ans << 1) + 1 << endl;
    return 0;
}