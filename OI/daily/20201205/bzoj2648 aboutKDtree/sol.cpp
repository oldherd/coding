#include <bits/stdc++.h>

const int N = 500010;

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
} a[N];

inline bool operator == (const point& lhs, const point& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline int get_dis(point &x, point &y) { return abs(x.x - y.x) + abs(x.y - y.y); }

namespace kdtree {
    const int N = 1000010, inf = 0x3f3f3f3f;
    int ch[N][2], x[N][2], y[N][2], tot;
    point P[N];
    bool cmp0(point x, point y) { return x.x < y.x; }
	bool cmp1(point x, point y) { return x.y < y.y; }
    inline void init() {
        x[0][0] = inf, x[0][1] = -inf;
        y[0][0] = inf, y[0][1] = -inf;
    }
    inline int newnode(point& pt) {
        P[++tot] = pt;
        repp(i,0,2) x[tot][i] = pt.x, y[tot][i] = pt.y;
        return tot;
    }
    inline void update(int p) {
        x[p][0] = std::min(x[p][0], std::min(x[ch[p][0]][0], x[ch[p][1]][0]));
        x[p][1] = std::max(x[p][1], std::max(x[ch[p][0]][1], x[ch[p][1]][1]));
        y[p][0] = std::min(y[p][0], std::min(y[ch[p][0]][0], y[ch[p][1]][0]));
        y[p][1] = std::max(y[p][1], std::max(y[ch[p][0]][1], y[ch[p][1]][1]));
    }
    void build(int p, int lp, int rp, int tag) {
        int mid = lp + rp >> 1;
        if(~tag) std::nth_element(a + lp, a + mid, a + rp + 1, cmp0);
        else std::nth_element(a + lp, a + mid, a + rp + 1, cmp1);
        P[p] = a[mid];
        repp(i,0,2) x[p][i] = P[p].x, y[p][i] = P[p].y;
        if(lp != mid) build(ch[p][0] = ++tot, lp, mid - 1, -tag);
        if(mid != rp) build(ch[p][1] = ++tot, mid + 1, rp, -tag);
        update(p);
    }
    void insert(int p, point &pt, int tag) {
        if(pt == P[p]) return;
        if(~tag&&cmp0(pt, P[p]) || tag&&cmp1(pt, P[p])) {
            if(ch[p][0]) insert(ch[p][0], pt, -tag);
            else ch[p][0] = newnode(pt);
        } else {
            if(ch[p][1]) insert(ch[p][1], pt, -tag);
            else ch[p][1] = newnode(pt);
        }
        update(p);
    }
    int ans = inf;
	inline int gen_eva(point &pt, int p) {
        return std::max(x[p][0]-pt.x,0)+std::max(pt.x-x[p][1],0)+std::max(y[p][0]-pt.y,0)+std::max(pt.y-y[p][1],0);
    }
    void query(int p, point &pt, int tag) {
        ans = std::min(ans, get_dis(pt, P[p]));
        int d[2];
        if(ch[p][0]) d[0] = gen_eva(pt, ch[p][0]); else d[0] = inf;
        if(ch[p][1]) d[1] = gen_eva(pt, ch[p][1]); else d[1] = inf;
        int mi = d[0]>=d[1];
        if(d[mi] < ans) query(ch[p][mi], pt, -tag);
        if(d[1-mi] < ans) query(ch[p][1-mi], pt, -tag);
    }
    inline int query(point& pt) {
        ans = inf;
        query(1, pt, 1);
        return ans;
    }
    
}

int main() {
    int n, m, t, x, y;
    std::cin >> n >> m;
	rep(i,1,n) {
		std::cin >> x >> y;
		a[i] = point(x, y);
	}
	kdtree::build(1, 1, n, 1);
	rep(i,1,m) {
		std::cin >> t >> x >> y;
		point p(x, y);
		if(t == 1) {
			kdtree::insert(1, p, 1);	
		} else {
			std::cout << kdtree::query(p) << std::endl;
		}
	}
    return 0;
}
