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
vector<int> vs[N];
int a[N] , pre[N] , suff[N] , bb[N << 1];

int dat[N<<2] , tag[N<<2];
void pushdown(int p) {
    dat[p<<1] = dat[p<<1|1] = tag[p]; tag[p] = 0;
}

void assign(int p , int lp , int rp , int l , int r , int v) {
    if(l <= lp && rp <= r) {
       dat[p] = tag[p] = v;
       return ;
    }
    int mid = lp + rp >> 1;
    if(tag[p]) pushdown(p);
    if(l <= mid) assign(p<<1 , lp , mid , l , r , v);
    if(r > mid) assign(p<<1|1 , mid + 1 , rp , l , r , v);
}

int qry(int p , int lp , int rp , int x) {
    if(x == lp) return dat[p];
    int mid = lp + rp >> 1;
    return x <= mid ? qry(p<<1,lp,mid,x) : qry(p<<1|1,mid+1,rp,x);
}

int main() {
    int tests;
    cin >> tests;
    while(tests--) {
        int n;
        cin >> n;
        rep(i,1,n) cin >> a[i] , pre[i] = pre[i-1] + a[i];
        per(i,n,1) suff[i] = suff[i+1] + a[i];
        per(i,n,1) suff[i] = -suff[i];
        rep(i,1,n) bb[i] = suff[i]; bb[n+1] = 0;
        sort(bb + 1 , bb + n + 2); int be = unique(bb + 1 , bb + n + 2) - bb - 1;
        rep(i,1,be) vs[i].clear();
        rep(i,0,n+1) vs[lower_bound(bb+1,bb+be+1,suff[i])-bb].push_back(i);
        rep(i,1,be) sort(vs[i].begin() , vs[i].end());
        rep(i,1,be) {
            for(auto qwq : vs[i]) cout << qwq << ' ';
            cout << endl;
        }
        rep(i,1,n) {
            int id = lower_bound(bb+1,bb+be+1,pre[i-1])-bb;
            vector<int>::iterator it = lower_bound(vs[id].begin() , vs[id].end() , i);
            assign(1 , 1 , n , i , *it , (*it) - i);
        }
        ll ans = 0;
        rep(i,1,n) ans += qry(1,1,n,i);
        cout << ans << endl;
    }
    return 0;
}
