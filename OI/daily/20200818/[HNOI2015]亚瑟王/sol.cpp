#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(b);i>=(a);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

struct edge {
	int x, w;
	edge() {}
	edge(int x, int w): x(x), w(w) {}
};

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<edge> > Graph;

const int maxn = 230, maxr = 150; 

double f[maxn][maxr], p[maxn];
int d[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(10);
	int tests;
	cin >> tests;
	while(tests--) {
		int n, r;
		double ans = 0;
		cin >> n >> r;
		for(int i = 1; i <= n; ++i) cin >> p[i] >> d[i];
		for(int j = 1; j <= r; ++j) f[1][j] = pow(1 - p[1], j - 1) * p[1];	//ka
		for(int i = 1; i <= n; ++i) f[i][0] = 0;
		for(int i = 2; i <= n; ++i)
			for(int j = 1; j <= r; ++j) {
				double pij = (1 - f[i-1][j]) * (1 - f[i][j-1] + f[i-1][j-1]) * p[i]; 
				ans = ans + pij * d[i];
				f[i][j] = f[i - 1][j] + pij;
			}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) cout << f[i][j] << '\t';
			cout << '\n';
		}
		cout << ans << endl;
	}
	return 0;
}

