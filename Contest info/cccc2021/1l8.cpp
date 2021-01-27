#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int gen[] = {1, 1, 1, 1, 1, 1, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};

int main() {
	int a[10][10], sum = 0, x, y;
	rep(i,1,3) rep(j,1,3) cin >> a[i][j], sum += a[i][j];
	rep(i,1,3) rep(j,1,3) if(!a[i][j]) a[i][j] = 45 - sum;
	rep(i,1,3) {
		cin >> x >> y;
		cout << a[x][y] << endl;
	}
	cin >> x;
	int ans = 0;
	if(x >= 1 && x <= 3) {
		rep(i,1,3) ans += a[x][i];
	} else if(x >= 4 && x <= 6) {
		rep(i,1,3) ans += a[i][x-3];
	} else {
		if(x == 7) rep(i,1,3) ans += a[i][i];
		else rep(i,1,3) ans += a[i][4-i];
	}
	cout << gen[ans] << endl;
//	cout << gen[24] << endl;
	return 0;
}
