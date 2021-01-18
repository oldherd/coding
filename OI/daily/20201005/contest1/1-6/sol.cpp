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

const int N = 60;
string boy[N] , girl[N];
int cb[N] , cg[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , x , top1 = 0 , top2 = 0;
    cin >> n;
    rep(c,1,n) {
        cin >> x;
        if(x) ++top1 , cin >> boy[top1] , cb[top1] = c;
        else ++top2 , cin >> girl[top2] , cg[top2] = c;
    }
    int bl = 1 , br = n >> 1 , gl = 1 , gr = br;
    int cnt = 0;
    while(cnt != n>>1) {
        if(cb[bl] < cg[gl])
            cout << boy[bl++] << ' ' << girl[gr--] << endl;
        else
            cout << girl[gl++] << ' ' << boy[br--] << endl;
        ++cnt;
    }
    return 0;
}