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

inline void read(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

string num[25] = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"};
string grtr[10] = {"zero" , "ten" , "twenty" , "thirty" , "forty" , "fifty"};

void output(int x) {
	if(x < 20) {
		cout << num[x];
		return;
	}
	if(x % 10) cout << grtr[x / 10] << ' ' << num[x % 10];
	else cout << grtr[x / 10];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h , m;
	cin >> h >> m;
	output(h);
	cout << ' ';
	if(m) output(m);
	else cout << "o\'clock";
	cout << endl;
	return 0;
}
