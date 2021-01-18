#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define inl inline
typedef double db;
const db eps = 1e-9, pi = acos(-1);

int sign(double x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
int cmp(double x, double y) { return sign(x - y); }
//dot
struct P {
    db x, y;
    P();
    P(db x, db y) : x(x), y(y) {};
    P operator + (const P& o) const { return P(x+o.x , y+o.y); }
    P operator - (const P& o) const { return P(x-o.x, y-o.y); }
    P operator * (db o) const { return P(x*o, y*o); }
    P operator / (db o) const { return P(x/o, y/o); }
    bool operator < (const P& o) const { return cmp(x,o.x)<0 || cmp(x,o.x)==0&&cmp(y,o.y)<0; }
    bool operator == (const P& o) const { return cmp(x,o.x)==0 && cmp(y,o.y)==0; }
    friend P operator * (db o, const P& p) { return P(p.x*o, p.y*o); }
};

inline void readP(P &p) { scanf("%lf %lf", &p.x, &p.y); }
inl db alpha(P p) { return atan2(p.y, p.x); }
inl db len2(P p) { return p.x*p.x+p.y*p.y; }
inl db len(P p) { return sqrt(p.x*p.x+p.y*p.y); }
inl db dist(P p, P q) { return len(q - p); }
inl P unit(P p) { return p / len(p); }
inl int quad(P p) { return sign(p.y) == 1 || sign(p.y) == 0 && sign(p.x) >= 0; }
//vector
inl P rot(P p, db a) { return P(p.x*cos(a)-p.y*sin(a), p.y*cos(a)+p.x*sin(a)); }
inl P rot90(P p) { return P(-p.y, p.x); }
inl db dot(P p, P q) { return p.x * q.x + p.y * q.y; }
inl db det(P p, P q) { return p.x * q.y - p.y * q.x; }
inl bool cmp(P p, P q) { return quad(p)<quad(q) || quad(p)==quad(q)&&sign(det(p,q))>0; }
inline db rad(P p1, P p2) { return atan2(det(p1, p2), dot(p1, p2)); }
//line
inl db cross(P p1, P p2, P p3) { return det(p2-p1, p3-p1); }
inl int crossOp(P p1, P p2,P p3) { return sign(cross(p1, p2, p3)); }
inline bool isLL(P p1, P p2, P q1, P q2) { return sign(det(p2-p1, q2-q1)) != 0; }
inline int ltl(P p1, P p2, P q1, P q2) {
	if(crossOp(p1, p2, q1) == 0 && crossOp(p1, p2, q2) == 0) return 1;
	if(sign(det(p2-p1, q2-q1)) == 0) return 0;
	return -1;
}
inline P genLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
	return (q1 * a2 + q2 * a1) / (a1 + a2);
}
inl P proj(P q, P p1, P p2) {
	P unt = unit(p2 - p1);
	return p1 + unt * dot(unt, q - p1);
}
//segment
inline bool isSS_strict(P p1, P p2, P q1, P q2) {
    return crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<0 && crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<0;
}
inl bool inter(db l1, db r1, db l2, db r2) {
    if(l1 > r1) std::swap(l1, r1); if(l2 > r2) std::swap(l2, r2);
    return !(sign(r1-l2) == -1 || sign(r2-l1) == -1);
}
inl bool intersect(P p1, P p2, P q1, P q2) {
    return inter(p1.x, p2.x, q1.x, q2.x) && inter(p1.y, p2.y, q1.y, q2.y);
}
inl bool isSS(P p1, P p2, P q1, P q2) {
    return intersect(p1,p2,q1,q2) && crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<=0 && crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<=0;
}
inline bool isMid(db m, db a, db b) {
	return sign(a-m) == 0 || sign(b-m) == 0 || ((a < m) != (b < m));
}
inline bool isMid(P m, P a, P b) {
	return isMid(m.x, a.x, b.x) && isMid(m.y, a.y, b.y);
}
inline bool onSeg_strict(P p1, P p2, P q) {
	return crossOp(p1,p2,q) == 0 && sign(dot(q-p1, p1-p2)) * sign(dot(q-p2, p1-p2)) < 0;
}
inline bool onSeg(P q, P p1, P p2) {
	return crossOp(p1,p2,q) == 0 && sign(dot(q-p1,q-p2)) <= 0;
}
//dot&line&seg
inline P nerest(P q, P p1, P p2) {
	P h = proj(q, p1, p2);
	if(isMid(h, p1, p2)) return h;
	else return dist(p1, q) < dist(p2, q) ? p1 : p2; 
}
inline db disNearest(P q, P p1, P p2) {
	P h = proj(q, p1, p2);
	if(isMid(h, p1, p2)) return dist(q, h);
	return std::min(dist(p1, q), dist(p2, q));
}
inline P reflect(P q, P p1, P p2) {
	return  2 * proj(q, p1, p2) - q;
}
inline db disSS(P p1, P p2, P q1, P q2) {
	if(isSS(p1, p2, q1, q2)) return 0;
	return std::min(std::min(disNearest(p1, q1, q2), disNearest(p2, q1, q2)), std::min(disNearest(q1, p1, p2), disNearest(q2, p1, p2)));
}
//poly
inline db Spoly(const std::vector<P>& poly) {
	db ret = 0; int sz = poly.size() - 1;
	for(int i = 0; i < sz; ++i) ret += det(poly[i], poly[i+1]);
	return 0.5*(ret + det(poly[sz], poly[0]));
}
inline int contain(P p, const std::vector<p> poly) {
	int n = poly.size(); int ret = 0;
	for(int i = 0; i < n; ++i) {
		P p1 = poly[i], p2 = poly[(i + 1) % n];
		if(onSeg(p, p1, p2)) return 2;
		if(cmp(p1.y, p2.y) >= 0) swap(p1.y, p2.y);
		if(cmp(p.y, p2.y) > 0 || cmp(p.y, p1.y) <= 0) continue;
		if(crossOp(p1, p2, p) <= 0) ret = ret ^ 1;
	}
	return ret;
}
//套路 : 线段在图形内的长度 , 求出所有交点 , 排个序 , 判断一下每一段是否在多边形当中  

//convex hull
void genConvexHull(std::vector<P>& ps, std::vector<P>& ans) {
	unique(ps.begin(), ps.end()); int n = ps.size(); 
	if(n <= 1) { ans = ps; return ; }
	sort(pts.begin(), pts.end());
	ans.clear(); ans.push_back(ps[0], ps[1]);
	for()
}
