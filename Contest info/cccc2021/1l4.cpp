#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

//inline void read(int &x) {
//    char ch;
//    do { ch=getchar(); } while(ch < '0' || ch > '9');
//    do {} while();
//}

const db k[] = {2.455, 1.26};

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	db tmp, ans = 0;
	cin >> n;
	rep(i,1,n) {
		cin >> tmp;
		ans += 1 / tmp;
	}
	cout << n / ans;
	return 0;
}
