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
// typedef vector< vector<int> > Graph;

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

const int maxn = 100010;
int sum[maxn], a[maxn];
double f[maxn][110], C[maxn*5+100][10];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.sef(ios::fixed);
//	cout.precision(6);
//  ifstream in();
//  ofstream out();
//	out.setf(ios::fixed);
//	out.precision(6);
//	int tests;
//	cin >> tests;
//	while(tests--) {
//	}
    int n;
    cin >> n;
    rep(i,1,n) cin >> a[i], f[i][a[i]] = ;
    rep(i,1,n) C[i][0] = 1;
    rep(i,1,n)
        rep(j,1,5)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    rep(i,1,n) {
        rep(j,0,5)
            cout << C[i][j] << ' ';
        cout << endl;
    }

    return 0;
}