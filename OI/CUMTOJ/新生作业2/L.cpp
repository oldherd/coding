#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int dat[N << 2] , ys[N << 3];
void build(int p , int lp , int rp) {
	if(lp == rp) {
		dat[p] = ys[lp];
		return;
	}
	int mid = (lp + rp) >> 1;
	build(p<<1 , lp , mid);
	build(p<<1|1 , mid + 1 , rp);
	dat[p] = max(dat[p<<1] , dat[p<<1|1]);
}

int qry(int p , int lp , int rp , int l , int r) {
	if(l <= lp && rp <= r) return dat[p];
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l < mid) ans = qry(p<<1 , lp , mid , l , r);
	if(r >= mid) ans = max(ans , qry(p<<1|1 , mid + 1 , rp , l , r));
}

int gen(int x) {
	if(ys[x]) return ys[x];
	if(x % 2) return ys[x] = gen(x * 3 + 1);
	return ys[x] = gen(x / 2);
}

int main() {
	ys[1] = 1;
	rep(i,2,n) gen(i);
	
	return 0;
}
