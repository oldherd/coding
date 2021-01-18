#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)
#define inl inline 

using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const db eps = 1e-9;

struct P {
    db x , y;
    P() {};
    P(db x , db y) : x(x) , y(y) {};
    P operator + ( const P & o ) const { return P(x + o.x , y + o.y); }
    P operator - ( const P & o ) const { return P(x - o.x , y - o.y); }
    P operator * ( db o ) const { return P(x * o , y * o); }
    P operator / ( db o ) const { return P(x / o , y / o); }
    P operator -= ( const P & o ) { x -= o.x; y -= o.y; return *this; }
};
inl void readP( P & p ) { cin >> p.x >> p.y; }
inl int sign( db x ) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
inl int cmp( db x , db y ) { return sign(x - y); }
inl P rot90( P p ) { return P(-p.y , p.x); }
inl P rotBack90( P p ) { return P(p.y , -p.x); }
inl db dot( P p , P q ) { return p.x * q.x + p.y * q.y; }
inl db det( P p , P q ) { return p.x * q.y - p.y * q.x; }
inl int dotOp( P p , P q ) { return sign(dot(p , q)); }
inl int detOp( P p , P q ) { return sign(det(p , q)); }
P mid;
inl int quad( P p ) { return sign(p.y) == 1 || sign(p.y) == 0 && sign(p.x) == 1; }
inl bool cmper( P p , P q ) { p -= mid; q -= mid; return quad(p) < quad(q) || quad(p) == quad(q) && detOp(p , q) == 1; }
inl bool samePoint( P p , P q ) { return !cmp(p.x,q.x) && !cmp(p.y,q.y); }

const int N = 2010;
P ps[N] , pq[N] , pn[N];
ll ans[N];
int ipq[N] , n , q;

int find(int l , int r , P p) {
    while(l < r) {
        int md = l + r + 1 >> 1;
        if(cmper(pn[md] - mid , p - mid) || (dotOp(pn[md]-mid , p-mid) == 1 && detOp(pn[md]-mid,p-mid) == 0)) l = md;
        else r = md - 1;
    }
    return l;
}

ll calc(P md) {
    mid = md;
    int nn = 0;
    rep(i,1,n) if(!samePoint(ps[i] , md)) pn[++nn] = ps[i];
    sort(pn + 1 , pn + nn + 1 , cmper);
    ll ans = 0;
    rep(i,1,nn) {
        int idx = find(1 , nn , rot90(pn[i]-mid)+mid) , idy = idx;
        if(dotOp(pn[i]-mid , pn[idx]-mid) != 0) continue;
        while(idx > 1 && dotOp(pn[i]-mid , pn[idx-1]-mid) == 0 && detOp(pn[i]-mid,pn[idx-1]-mid) == 1) --idx;
        while(idy < nn && dotOp(pn[i]-mid , pn[idy+1]-mid) == 0 && detOp(pn[i]-mid , pn[idy+1]-mid) == 1) ++idy;
        ans += idy - idx + 1;
    }   
    return ans;
}

void work(int idMid) {
    int nn = 0; mid = ps[idMid];
    rep(i,1,n) if(idMid != i && !samePoint(mid , ps[i])) pn[++nn] = ps[i];
    sort( pn + 1 , pn + nn + 1 , cmper );
    rep(i,1,q) {
        if(samePoint(pq[i] , mid)) continue;
        int idx = find(1 , nn , rot90(pq[i]-mid)+mid) , idy = idx;
        if(dotOp(pq[i]-mid , pn[idx]-mid) == 0 && detOp(pq[i]-mid , pn[idx]-mid) == 1) {
            while(idx > 1 && dotOp(pn[idx-1]-mid,pq[i]-mid) == 0 && detOp(pq[i]-mid , pn[idx-1]-mid) == 1) --idx;
            while(idy < nn && dotOp(pq[i]-mid , pn[idy+1]-mid) == 0 && detOp(pq[i]-mid , pn[idy+1]-mid) == 1) ++idy;
            ans[i] += idy - idx + 1;
            // cout << mid.x << ',' << mid.y << '$' << pq[i].x << ',' << pq[i].y << "$$$$$$$" << endl;
            // rep(i,idx,idy) cout << pn[i].x << ',' << pn[i].y << endl;
            // cout << "$$$$$$$$" << endl;
        }
        idx = find(1 , nn , rotBack90(pq[i]-mid)+mid) , idy = idx;
        if(dotOp(pq[i]-mid , pn[idx]-mid) == 0 && detOp(pq[i]-mid , pn[idx]-mid) == -1) {
            while(idx > 1 && dotOp(pn[idx-1]-mid,pq[i]-mid) == 0 && detOp(pq[i]-mid , pn[idx-1]-mid) == -1) --idx;
            while(idy < nn && dotOp(pq[i]-mid , pn[idy+1]-mid) == 0 && detOp(pq[i]-mid , pn[idy+1]-mid) == -1) ++idy;
            ans[i] += idy - idx + 1;
            // cout << mid.x << ',' << mid.y << '$' << pq[i].x << ',' << pq[i].y << "$$$$$$$" << endl;
            // rep(i,idx,idy) cout << pn[i].x << ',' << pn[i].y << endl;
            // cout << "$$$$$$$$" << endl;
        }
    }
}------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> q;
    rep(i,1,n) readP(ps[i]);
    rep(i,1,q) readP(pq[i]);
    rep(i,1,q) ans[i] = calc(pq[i]);
    // rep(i,1,q) cout << ans[i] << ' ';
    // cout << endl;
    rep(i,1,n) 
        work(i);
    rep(i,1,q) cout << ans[i] << endl;
    return 0;
}