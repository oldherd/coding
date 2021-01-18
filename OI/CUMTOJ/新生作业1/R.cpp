#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(b);i>=(a);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

struct edge {
	int x, w;
	edge() {}
	edge(int x, int w): x(x), w(w) {}
};

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;
typedef vector< vector<edge> > Graph;

inline void read(int &x) {
	char ch; int f = 1; x=0;
	do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
	do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
	x *= f;
}

const int M = 30 , N = 100;
char key[M] , str[N];

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
//	freopen("ylR.in" , "r" , stdin);
	while(~scanf("%s" , key)) {
		getchar();
		scanf("%[^\n]s" , str);
		int len = strlen(str);
		rep(i,0,len-1) {
			if(str[i] >= 'a' && str[i] <= 'z') putchar(key[str[i]-'a']);
			else if(str[i] >= 'A' && str[i] <= 'Z') putchar(key[str[i]-'A']-'a'+'A');
			else if(str[i] == ' ') putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

