#include <bits/stdc++.h>

using namespace std;

const int N = 40010;
int stk[N] , top , n;

int ret;
void dfs(int cur , int flg , int mul) {
	if(cur == top + 1) {
		if(mul == 1) return;
		ret += flg * (n - n / mul);
		return;
	}
	dfs(cur + 1 , -flg , mul * stk[cur]);
	dfs(cur + 1 , flg , mul);
}

int calc(int k) {
	for(int i = 2; i <= k && k > 1; ++i) {
		if(!k % i) {
			stk[++top] = i;
			while(!(k % i))	k /= i;		
		}
	}
	ret = 0;
	dfs(1 , -1 , 1);	
	return ret;
}

int main() {
	int ans;
	cin >> n;
	for(int i = 2; i <= n; ++i)
		ans += calc(i) , cout << ans << ' ';
	cout << endl;
	cout << ans + n << endl;
	return 0;
}
