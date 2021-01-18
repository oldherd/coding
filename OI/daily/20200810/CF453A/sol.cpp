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

int main() {
	cout.setf(ios::fixed);
	cout.precision(13);
	int m, n;
	double ans = 0, mn = 0;
	cin >> m >> n;
	for(int k = 1; k <= m; ++k)
		ans += k * (pow((double)k / m, n) - pow((double)(k - 1) / m, n));
	cout << ans << endl;
	return 0;
}

