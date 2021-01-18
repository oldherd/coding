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

const int maxn = 100010;
int s[maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n, a, b;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        if(s[i] % 2) ++a;
        else ++b;
    }
    
    return 0;
}