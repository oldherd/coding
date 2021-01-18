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

const int N = 110 , inf = 0x7f7f7f7f;
int a[N][N] , n , m;
int rowMin[N] , colMax[N];

int findRowMin(int row) {
	int ret = inf;
	rep(j,1,m) if(ret > a[row][j]) ret = a[row][j];
	return ret;
}

int findColMax(int col) {
	int ret = -inf;
	rep(i,1,n) if(a[i][col] > ret) ret = a[i][col];
	return ret;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	scanf("%d %d" , &n , &m);
	rep(i,1,n) rep(j,1,m)
		scanf("%d" , &a[i][j]);
	rep(i,1,n) rowMin[i] = findRowMin(i);
	rep(j,1,m) colMax[j] = findColMax(j);
	bool flg = true
	rep(i,1,n)
		rep(j,1,m)
			if(a[i][j] == rowMin[i] && a[i][j] == colMax[j])
				printf("%d %d %d\n" , i , j , a[i][j]) , flg = false;
	if(flg) printf("no find\n");
	return 0;
}

