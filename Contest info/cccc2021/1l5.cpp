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
	int q[10], x, y, mx = -1, cnt = 0, bd = -1;
	rep(i,1,4) cin >> q[i], mx = max(mx, q[i]);
	cin >> x >> y;
	rep(i,1,4) {
		if(mx - q[i] > y || q[i] < x) {
			++cnt; bd = i;	
		}
	}
	if(cnt == 0) {
		cout << "Normal";
	} else if(cnt == 1) {
		printf("Warning: please check #%d!", bd);
	} else {
		printf("Warning: please check all the tires!");
	}
	return 0;
}
