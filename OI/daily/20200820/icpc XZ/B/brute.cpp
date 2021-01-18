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

int a[100];

bool check(int n) {
    for(int i = 2; i <= n; ++i) {
        if(abs(a[i] - a[i - 1]) > 1) return false;
    }
    return true;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    for(int k = 1; k <= 20; ++k) {
        int cnt = 0;
        for(int i = 1; i <= k; ++i) a[i] = i;
        do {
            if(check(k)) ++cnt;
        } while(next_permutation(a + 1, a + k + 1));
        printf("%d\n", cnt);
    }
    return 0;
}