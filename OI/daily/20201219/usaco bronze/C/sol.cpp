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

struct point{ int x, y, tx, ty, id, ans, nt; bool live; point(){} point(int x,int y, int id):x(x),y(y),id(id){ live = true; tx = x; ty = y; } };

const int N = 1010;

vector<point> e, n;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int nn, xi, yi;
    char dir[5];
    cin >> nn;
    rep(i,1,nn) {
        cin >> dir >> xi >> yi;
        if(dir[0] == 'E') e.push_back(point(xi,yi,i));
        else n.push_back(point(xi,yi,i));
    }
    const int inf = 1000000010;
    while(true) {
        int tm = inf;
        for(point &p : e) if(p.live) {
            p.nt = inf;
            for(point pp : e) {
                if(pp.id != p.id && pp.y == p.y && pp.x > p.tx) p.nt = min(p.nt, pp.x - p.tx);
            }
            for(point pp : n) {
                if(pp.live && pp.y <= p.y && p.y - pp.y < pp.x - p.x) p.nt = min(p.nt, pp.x - p.tx);
                if(!pp.live && pp.y <= p.y && p.y <= pp.ty) p.nt = min(p.nt, pp.x - p.tx);
            }
            tm = min(tm, p.nt);
        }
        for(point &p : n) if(p.live) {
            p.nt = inf;
            for(point pp : n) if(pp.id != p.id && pp.x == p.x && pp.y > p.y) p.nt = min(p.nt, pp.y - p.ty);
            for(point pp : e) {
                if(pp.live && pp.x <= p.x && p.x - pp.x < pp.y - p.y) p.nt = min(p.nt, pp.y - p.ty);
                if(!pp.live && pp.x <= p.x && pp.tx >= p.x) p.nt = min(p.nt, pp.y - p.ty);
            }
            tm = min(tm, p.nt);
        }
        if(tm == inf) break;
        // cout << tm << endl;
        for(point &p : e) if(p.live) {
            if(p.nt == tm) p.tx += tm - 1, p.live = false, p.ans = p.tx - p.x + 1;
            else p.tx += tm;
        }
        for(point &p : n) if(p.live) {
            if(p.nt == tm) p.ty += tm - 1, p.live = false, p.ans = p.ty - p.y + 1;
            else p.ty += tm;
        }
    }
    // for(point& p : e) {
    //     int inf = 1000000001;
    //     for(point pp : e) 
    //         if(pp.id != p.id && pp.y == p.y && pp.x > p.x) inf = min(inf, pp.x-1);
    //     for(point pp : n) 
    //         if(pp.y <= p.y && p.y - pp.y < pp.x - p.x) inf = min(inf, pp.x-1);
    //     p.ans = inf == 1000000001 ? inf : inf - p.x + 1;
    // }
    // for(point& p : n) {
    //     int inf = 1000000001;
    //     for(point pp : n) if(pp.id != p.id && pp.x == p.x && pp.y > p.y) inf = min(inf, pp.y - 1);
    //     for(point pp : e) if(pp.x <= p.x && p.x - pp.x < pp.y - p.y) inf = min(inf, pp.y - 1);
    //     p.ans = inf == 1000000001 ? inf : inf - p.y + 1;
    // }
    vector<point> v;
    for(point p : e) v.push_back(p);
    for(point p : n) v.push_back(p);
    sort(v.begin(), v.end(), [&](point p1, point p2) { return p1.id < p2.id; });
    for(point p : v) {
        if(p.live) cout << "Infinity" << endl;
        else cout << p.ans << endl;
    }
    return 0;
}
