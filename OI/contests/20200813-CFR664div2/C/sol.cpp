#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

//struct edge {
//	int x, w;
//	edge() {}
//	edge(int x, int w): x(x), w(w) {}
//};

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
//typedef vector< vector<edge> > Graph;

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

const int maxn = 210;

int a[maxn], b[maxn];
bool vis[maxn][maxn];


int main() {

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
    int ans = 0;
    for(int k = 8; ~k; --k) {
        int bs = 1 << k, cnt = 0;
        if(k == 3) {
        	int t = k;
        	t = k;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(!vis[i][j] && (((a[i] & b[j]) & bs) == 0)) {
                    ++cnt; break;
                }
            }
        }
        if(cnt == n) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= m; ++j) {
                    if((a[i] & b[j]) & bs) {
                        vis[i][j] = true;
                    }
                }
            }
       } else ans |= bs;
    }
    cout << ans << endl;
    return 0;
}
