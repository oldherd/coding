#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

const int N = 15 , inf = 0x7f7f7f7f;
int mp[1<<N] , No1[1<<N] , n , m , u , v , ans = inf , bitAns;

void init() {
	int ed = 1<<13; No1[0] = 0; No1[1] = 1;
	repp(i,2,ed) No1[i] = No1[i>>1] + (i%2);
}

inline int getNo1(int bit) {
	return No1[bit>>13] + No1[bit^((bit>>13)<<13)];
}

void dfs(int cur , int bit , int noe) {
	if(cur == n) {
		if(getNo1(bit)<<1 == n && noe < ans) ans = noe , bitAns = bit;
		return ;	
	}
	if(((n - cur + getNo1(bit))<<1) < n || (getNo1(bit)<<1) > n) return;
	dfs(cur + 1 , bit + (1<<cur) , noe + getNo1((~bit&((1<<(cur+1))-1))&mp[cur]));
	dfs(cur + 1 , bit , noe + getNo1(bit&mp[cur]));
}

int main() {
	cin >> n >> m;
	rep(i,1,m) {
		cin >> u >> v; --u; --v;
		mp[u] |= (1<<v);
		mp[v] |= (1<<u);
	}
	init();
	dfs(0 , 0 , 0);
	rep(i,1,n) {
		if(bitAns%2) cout << i << ' ';
        bitAns>>=1;
	}
    cout << endl;
	return 0;
}