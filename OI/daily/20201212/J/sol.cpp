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

const int ss = 20;
vector<int> state;
int nt[ss];
bool flg = false;
void dfs(int p, int n, int k) {
    if(p == n + 1) {
        bool flg = true;
        for(int i = 1; i + k - 1 <= n; ++i) {
            int a = 0;
            for(int j = 0; j < k; ++j) a = (a << 1) | nt[j+i];
            if(!nt[a+1]) flg = false;
        }
        if(flg) {
            int a = 0; rep(i,1,n) a = (a<<1) | nt[i];
            state.push_back(a);
        }
        return;
    }
    nt[p] = 0;
    dfs(p+1, n, k);
    nt[p] = 1;
    dfs(p+1, n, k);
}

const int maxs = 310, maxn = 510;
int f[maxs][maxn][20];

const int Mod = 998244353;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}

int main() {
    int n, k;
    cin >> n >> k;
    if(n <= (1<<k)) {
        dfs(1, n, k);
        cout << state.size() << endl;
    } else {
        dfs(1, 1<<k, k);
        int t = 1<<k;
        for(int s = 0; s < state.size(); ++s) {
            f[s][0][state[s]%t] = 1;
            for(int i = 1; i + t <= n; ++i) {
                rep(w,0,t-1) {
                    if(state[s] & 1<<(t-1-w)) {
                        f[s][i][w] = Inc(f[s][i-1][(w%t)>>1], f[s][i][w]);
                        f[s][i][w] = Inc(f[s][i-1][((w%t)>>1)|(t>>1)], f[s][i][w]);
                    }
                }
            }
        }
        int ans = 0;
        for(int s = 0; s < state.size();++s) {
            rep(w,0,t-1) {
                ans = Inc(ans, f[s][n-t][w]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}