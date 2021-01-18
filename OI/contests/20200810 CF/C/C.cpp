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
typedef vector< vector<int> > Graph;

inline void read(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

const ll p = 1000000007;

ll gen(int n) {
	ll ans = 1, dd = 1;
	for(int i = 1; i <= n; ++i) ans = ans * i % p;
	for(int i = 1; i < n; ++i) dd = dd * 2 % p;
//	cout << ans << ' ' << dd << endl;
	return ((ans - dd) % p + p) % p;
}

int main() {
	int n;
	cin >> n;
	cout << gen(n) << endl;
	return 0;
}
