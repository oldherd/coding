#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)
#define inl inline

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int N = 50010, NN = 50000;
int Prime[N], vp[N], mu[N], low[N], tot;
void seive(int n) {
    mu[1] = low[1] = 1;
    rep(i,2,n) {
        if(!vp[i]) Prime[++tot] = i, low[i] = i, mu[i] = -1;
        for(int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
            vp[i*Prime[j]] = 1;
            if(i%Prime[j] == 0) {
                low[i*Prime[j]] = low[i] * Prime[j];
                // if(low[i] == i) mu[i*Prime[j]] = 0;
                // else mu[i*Prime[j]] = mu[i/low[i]] * mu[low[i]*Prime[j]];
                mu[i*Prime[j]] = 0;
                break;
            }
            low[i*Prime[j]] = Prime[j];
            mu[i*Prime[j]] = -mu[i];
        } 
    }
}

// inl int nex(int n, int k) { return n / (n / k); }

ll calc(int N, int M) {
    int nn = min(N, M);
    ll res = 0;
    for(int l = 1, r; l <= nn; l = r + 1) {
        r = min(nn, min(N/(N/l), M/(M/l)));
        res += 1ll * (mu[r] - mu[l-1]) * (N/l) * (M/l);
    }
    return res;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    seive(NN);
    rep(i,1,NN) mu[i] += mu[i-1];
    int tests;
    cin >> tests;
    rep(test,1,tests) {
        int a, b, c, d, k, A, B, C, D;
        cin >> a >> b >> c >> d >> k; --a; --c;
        ll ans = 0;
        A = a/k, B = b/k, C = c/k, D = d/k;
        ans += calc(B,D) - calc(A,D) - calc(B,C) + calc(A,C);
        cout << ans << endl;
    }
    return 0;
}