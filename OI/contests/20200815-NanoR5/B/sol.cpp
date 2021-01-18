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

const int maxn = 1000010, inf = 0x3f3f3f3f;
int d1[maxn], d2[maxn];

queue<int> q;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    int n, m, p;
    cin >> n >> m >> p;
    if(n == m) {
        cout << 0 << endl;
        return 0;
    }
    d1[n] = 0;
    q.push(n);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(d1[cur * 2 % p] == inf) {
            d1[cur * 2 % p] = d1[cur] + 1;
            q.push(cur * 2 % p);
        }
        if(d1[(cur + 1) % p] == inf) {
            d1[(cur + 1) % p] = d1[cur] + 1;
            q.push((cur + 1) % p);
        }
    }
    d2[m] = 0;
    q.push(m);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(d2[cur * 2 % p] == inf) {
            d2[cur * 2 % p] = d2[cur] + 1;
            q.push(cur * 2 % p);
        }
        if(d2[(cur + 1) % p] == inf) {
            d2[(cur + 1) % p] = d2[cur] + 1;
            q.push((cur + 1) % p);
        }
    }
    int ans = inf;
    for(int i = 0; i < p; ++i) {
        ans = min(ans, d1[i] + d2[i]);
    }
    // repp(i,0,p) cout << d1[i] << ' ';
    // cout << endl;
    // repp(i,0,p) cout << d2[i] << ' ';
    // cout << endl;
    cout << ans << endl;
    return 0;
}