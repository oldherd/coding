#include <iostream>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef double db;

const db pi = acos(-1), eps = 1e-7;

db sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }

int main() {
	int a, b;
	while(cin >> a >> b) {
		int g = __gcd(a, b);
		a /= g; b /= g;
		db delta = a * a - 4 * b;
		if(sign(delta) < 0) {
			cout << "No Solution" << endl;
			continue;
		}
		int sq = sqrt(delta);		
		if(sign(delta - sq * sq) == 0) {
			int t = a + sq;
			if(t % 2) {
				cout << "No Solution" << endl;
			} else {
				int x2 = (a + sq) / 2, x1 = (a - sq) / 2;
				if(__gcd(x1, x2) != 1) {
					cout << "No Solution" << endl;
				} else {
					cout << 1ll * x1 * g << ' ' << 1ll * x2 * g << endl;
				}
			}
		} else cout << "No Solution" << endl;
	}
	return 0;
}
