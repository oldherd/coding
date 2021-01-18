#include <iostream>
#include <cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef double db;

const db pi = acos(-1);

int main() {
	cout.setf(ios::fixed);
	cout.precision(3);
	int n, d, tmp;
	while(cin >> n >> d) {
		double dg, ans = 0;
		rep(i,1,n) {
			cin >> tmp;
			dg = 2 * pi * tmp / 360;
			ans += d * d * sin(dg);
		}
		cout << 0.5 * ans << endl;
	}
	return 0;
}
