#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;

const int N = 300010;
int h[N] , lhi[N] , rhi[N] , llow[N] , rlow[N] , f[N];

deque<int> qMax , qMin;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n) cin >> h[i];
	qMax.push_back(1);
	qMin.push_back(1);
	rep(i,2,n) {
		while(!qMax.empty() && h[qMax.end()] < h[i]) qMax.pop_back();
		if(!qMax.empty()) lhi[i] = qMax.back(); else lhi[i] = -1;
		qMax.push_back(i);
		while(!qMin.empty() && h[qMin.back()] > h[i]) qMin.pop_back();
		if(!qMin.empty()) llow[i] = qMin.back(); else llow[i] = -1;
		qMin.push_back(i);
	}
	qMax.clear();
	qMin.clear();
	qMax.push_back(n);
	qMin.push_back(n);
	per(i,n-1,1) {
		while(!qMax.empty() && h[qMax.back()] < h[i]) qMax.pop_back();
		if(!qMax.empty()) rhi[i] = qMax.back(); else rhi[i] = -1;
		qMax.push_back(i);
		while(!qMin.empty() && h[qMin.end()] > h[i]) qMin.pop_back();
		if(!qMin.empty()) rlow[i] = qMin.end(); else rlow[i] = -1;
		qMin.push_back(i);
	}
	memset(f , 0x3f , sizeof(f));
	f[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		if(cur != 1) {
			if(f[cur] + 1 < f[cur - 1]) {
				f[cur - 1] = f[cur] + 1;
				q.push(cur - 1);
			}
			if(h[cur - 1] < h[cur]) {
				int x = lhi[cur];
				while(~x) {
					if(f[cur] + 1 < f[x]) {
						f[x] = f[cur] + 1;
						q.push(x);
					}
				}
			}
		}
		if(cur != n) {
			if(f[cur] + 1 < f[cur + 1]) {
				f[cur + 1] = f[cur] + 1;
				q.push(cur + 1);
			}
			int x = 
		}
	}
	return 0;
}
