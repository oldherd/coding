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

const int N = ;
int Prime[N] , vp[N] , tot;

void seive(int n) {
    tot = 0;
    for(int i = 2; i <= n; ++i) {
        if(!vp[i]) Prime[++tot] = i;
        for(int j = 1; j <= tot && Prime[j] * i <= tot; ++j) {
            vp[i * Prime[j]] = 1;
            if(!(i % Prime[j])) break;
        }
    }
}

int unPrime[M] , Prime[M];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    ll l , r;
    seive(2147483647 + 10.0);
    while(cin >> l >> r) {
        rep(i,1,tot)
            for(ll j = Prime[i] * max((l + Prime[i] - 1) / Prime[i] , 2); j <= r; j += Prime[i])
                unPrime[j-l+1] = 1;
        int top = 0;
        rep(i,l,r) if(!unPrime[i-l+1]) Prime[++tot] = i;
        int mi = 1 , mx = 1;
        rep
    }
    return 0;
}