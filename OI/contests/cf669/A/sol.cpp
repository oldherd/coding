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

const int maxn = 1234;
vector<int> a , ans;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        a.clear();
        int n , sum = 0;
        scanf("%d", &n);
        a.resize(n + 1);
        for(int i = 1; i <= n; ++i) scanf("%d" , &a[i]) , sum += a[i];
        if(sum % 2 != 0) {
           for(vector<int>::iterator it = a.begin(); it != a.end();++it)
                if(*it) {
                    a.erase(it); --n;
                    break;
                } 
        }
        if(n == 1) {
            printf("1\n0\n");
            continue;
        }
        ans.clear();
        int l = -1;
        for(int i = 1; i <= n; ++i) {
            if(a[i]) {
                if(~l) {
                    if((i-1-l+1) % 2 == 0)
                        for(int j = l; j < i; ++j) ans.push_back(0);
                    else 
                        for(int j = l; j < i - 1; ++j) ans.push_back(0);
                }
                ans.push_back(1);
                l = -1;
            } else {
                if(!~l) l = i;
            }
        }
        if(~l) for(int i = l; i <= n; ++i) ans.push_back(0);
        int sz = ans.size();
        printf("%d\n" , sz);
        for(int i = 0; i < sz; ++i) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
