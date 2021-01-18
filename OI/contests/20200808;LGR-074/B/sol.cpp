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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	if(a == 0 && b == 0) printf("0\n");
	else if(a == 0 || b == 0) printf("%lld\n", d);
	else if(a == b) printf("%lld\n", min(c, 2 * d));
	else printf("%lld\n", min(c + d, 2 * d));
	return 0;
}

