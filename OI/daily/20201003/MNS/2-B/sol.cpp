#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int N = 100010 , L = 30;
map<pair<string,string>,int> h1;
map<string,int> h2;
string ming[N] , xing[N];
int qaq[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    rep(i,1,n) {
        cin >> ming[i] >> xing[i];
        if(xing[i][xing[i].length()-1] == 'n') qaq[i] = 0;
        else qaq[i] = 1;
    }
    rep(i,1,n) {
        
    }
    return 0;
}