#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int N = 10010;
int stk1[N], top1, top2;
char stk2[N];

int main() {
	int n;
	cin >> n;
	top1 = top2 = 0;
	rep(i,1,n) cin >> stk1[++top1];
	rep(i,1,n-1) cin >> stk2[++top2];
	bool flg = true;
	int m = -1;
	while(top2) {
		int a1 = stk1[top1--], a2 = stk1[top1--], res;
		char op = stk2[top2--];
		if(op == '+') res = a2 + a1;
		else if(op == '-') res = a2 - a1;
		else if(op == '*') res = a2 * a1;
		else if(op == '/') {
			if(a1) res = a2 / a1;
			else {
				flg = false; m = a2;
				break;
			}
		}
		stk1[++top1] = res;
	}
	if(flg) cout << stk1[1] << endl;
	else printf("ERROR: %d/0", m);
	return 0;
}
