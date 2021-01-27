#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef double db;

const int N = 110, tl = 13;
const char* ss = "chi1 huo3 guo1";
char str[110];

inline bool check(int id) {
	for(int i = 0; i <= tl; ++i) if(str[i+id] != ss[i]) return false;
	return true;
}

int main() {
	int tot = 0, fir = -1, cnt = 0;
	while(true) {
		cin.getline(str, 100);
		int len = strlen(str);
		if(len == 1 && str[0] == '.') break;
		++tot;
		bool flg = false;
		for(int i = 0; i + tl - 1 < len; ++i) {
			if(check(i)) {
				flg = true;
				break;
			}
		}
		if(flg && fir == -1) fir = tot;
		if(flg) ++cnt;
	}
	cout << tot << endl;
	if(~fir) cout << fir << ' ' << cnt;
	else cout << "-_-#";
	return 0;
}
