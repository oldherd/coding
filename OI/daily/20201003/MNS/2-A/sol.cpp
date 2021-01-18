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

struct edge {
    int x;
    edge() {}
    edge(int x): x(x) {}
};
typedef vector< vector<int> > Graph;

const int N = 1000010;
int dpt[N] , cnt[N] , l , r;
int isPrime[N];

inl int fp(int cur) { int ret = 0; while(cur) ret += (cur % 10) * (cur % 10) , cur /= 10; return ret; }

void work(int idx) {
    int nex = fp(idx);
    dpt[idx] = -1;
    if(nex == 1) {
        dpt[idx] = 1;
        return;
    }
    if(!dpt[nex]) work(nex);
    if(dpt[nex] < 0) dpt[idx] = -2;
    else {
        // if(nex >= l && nex <= r) dpt[idx] = dpt[nex] + 1;
        // else dpt[idx] = dpt[nex];
        dpt[idx] = dpt[nex] + 1;
        if(idx <= r && idx >= l) ++cnt[nex];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int l , r;
    cin >> l >> r;
    rep(i,l,r) {
        work(i);
    }
    isPrime[0] = isPrime[1] = isPrime[2] = 0;
    rep(i,2,r)
        if(!isPrime[i])
            for(int j = i * 2; j <= r; j += i) isPrime[j] = 1;
    // rep(i,2,r) if(!isPrime[i]) cout << i << ' ';
    // cout << endl;
    int ct = 0;
    rep(i,l,r) if(cnt[i] == 0 && dpt[i] > 0) cout << i << ' ' << dpt[i] * (isPrime[i] ? 1 : 2) << endl , ++ct;
    if(ct == 0) cout << "SAD" << endl;
    return 0;
}