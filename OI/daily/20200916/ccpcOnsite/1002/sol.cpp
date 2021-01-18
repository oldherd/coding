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

const int M = 41000000 , N = 200010;

struct node {
    int x , y;
    ll w;
    node() {}
    node(int x , int y , ll w) :x(x) , y(y) , w(w) {}
    bool operator < (const node& o) const { return w < o.w; }
}node[M];

int par[N];
int find(int x) { return x == par[x] ? x : x = find(par[x]); }
int top = 0;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int top = 0;
    rep(n,3,100) {
        rep(i,1,n)
            rep(j,i+1,n)
                if(i!=j) {
                    node[++top].w = (ll)(i+1) * (j+1) / __gcd(i+1,j+1);
                    node[top].x = i; node[top].y = j;
                }
        sort(node + 1 , node + top + 1);
        if(n==3) rep(i,1,top) printf("%d %d %lld\n" , node[i].x , node[i].y , node[i].w); 
        rep(i,1,n) par[i] = i;
        ll ans = 0;
        rep(i,1,top) {
            if((par[node[i].x] = find(node[i].x)) != (par[node[i].y] = find(node[i].y))) {
                par[par[node[i].x]] = par[node[i].y];
                ans += node[i].w;
            }
        }
        printf("%lld " , ans);
    }
    printf("\n");
    return 0;
}