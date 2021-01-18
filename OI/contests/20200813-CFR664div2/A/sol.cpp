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

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.sef(ios::fixed);
//	cout.precision(6);
//  ifstream in();
//  ofstream out();
//	out.setf(ios::fixed);
//	out.precision(6);
	int tests;
	cin >> tests;
	while(tests--) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int sum = (r % 2) + (g % 2) + (b % 2) + (w % 2);
        if(sum <= 1) cout << "Yes" << endl;
        else if(sum >= 3 && min(r, min(g, b)) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;   
    }
    return 0;
}