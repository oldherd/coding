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
	
	typedef double db;
	
	vector<int> v , odd , veven;
	
	void outTime(int hr , int mnt) {
		if(hr < 10) cout << '0';
		cout << hr << ':';
		if(mnt < 10) cout << '0';
		cout << mnt << ':';
	}
	
	typedef double db;
	db eps = 1e-9;
	inline int sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
	inline db hr(int x , int y) { return x * 30 + y / 12.0; }
	inline db mt( int x ) { return x * 6; }
	inline int check(int a , int b) {
		db a1 = hr(a , b) , b1 = mt(b);
		++b; if(b == 60) b = 0 , ++a;
		if(a == 12) a = 0;
		db a2 = hr(a , b) , b2 = mt(b);
		return sign(a1 - b1) * sign(a2 - b2) <= 0 && sign(a2 - b2) <= 0;
	}
	
	int work(int s1 , int s2 , int t1 , int t2) {
		int ret = 0;
		do {
			if(s1 == t1 && s2 == t2) break;
			ret += check(s1 , s2);
			++s2;
			if(s2 == 60) s2 = 0 , ++s1;
			if(s1 == 13) s1 = 1;
		}while(true);
		return ret;
	}
	
	int main() {
		//ios_base::sync_with_stdio(false);
		//cin.tie(NULL);
		int s1 , s2 , t1 , t2;
		cout << "Initial time  Final time  Passes" << endl;
		while(cin >> s1 >> s2 >> t1 >> t2) {
			rep(i,1,7) cout << ' ';
			outTime(s1 , s2);	
			rep(i,1,7) cout << ' ';
			outTime(t1 , t2);
			rep(i,1,7) cout << ' ';
			cout << work(s1==12?0:s1 , s2 , t1==12?t1:0 , t2) << endl;
		}
		return 0;
	}

