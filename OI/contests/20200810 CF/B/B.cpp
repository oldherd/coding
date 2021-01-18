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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while(tests--) {
		int n, m, cnt = 0;
		char ch;
		cin >> n >> m;
		string str; 
		for(int i = 1; i < n; ++i) {
			cin >> str;
			if(str[str.length() - 1] != 'D') ++cnt;
		}
		cin >> str;
		for(int i = 0; i < m - 1; ++i)
			if(str[i] != 'R') ++cnt;
		cout << cnt << endl;
	}
	return 0;
}

