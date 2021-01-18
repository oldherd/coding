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

const int Mod = 1000000007;
inl int Inc(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inl int Dec(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inl int Mul(int x, int y) { return 1ll * x * y % Mod; }

inl ll preSum(int l, int r) { return Mul(Inc(l, r), (Inc(Dec(r, l), 1)) inv(2); }

ll calc(int n, int N) {
    ll res = 0;
    for(int l = 1, r; l <= n; l = r + 1) {
        r = min(n, N/(N/l));
        res = Inc(res, Mul(preSum(l, r),  (N/l)));
    }
    return res;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    return 0;
}