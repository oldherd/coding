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

const int N = 100010 , inf = 0x7f7f7f7f;
char str[N];
int num[N << 1] , dat[N << 3];

inline int gen(char ch) { return ch == '(' ? 1 : -1; }

void build(int p, int lp, int rp) {
    if(lp == rp) {
        dat[p] = num[lp];
        return ;
    }
    int mid = lp + rp >> 1;
    build(p<<1 , lp , mid); build(p<<1|1 , mid + 1 , rp);
    dat[p] = min(dat[p<<1] , dat[p<<1|1]);
}

int qry(int p , int lp , int rp , int l , int r) {
    if(l <= lp && rp <= r) return dat[p];
    int mid = lp + rp >> 1 , ans = inf;
    if(l <= mid) ans = qry(p<<1 , lp , mid , l , r);
    if(r > mid) ans = min(qry(p<<1|1 , mid + 1 , rp , l , r) , ans);
    return ans;
}



int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    scanf("%d" , &tests);
    while(tests--) {
        int n;
        scanf("%d" , &n);
        scanf("%s" , str);
        rep(i,1,n) num[i] = num[i+n] = gen(str[i-1]);
        rep(i,2,n<<1)
            num[i] += num[i-1];
        build(1,1,n<<1);
        int ans = 0;
        rep(l,1,n) {
            int r = l + n - 1;
            if(qry(1 , 1 , n<<1 , l , r) - num[l-1] >= 0) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}