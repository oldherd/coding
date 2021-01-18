#include <cstdio>
#include <cmath>
#include <algorithm>

#define inl inline
typedef double db;

const db eps = 1e-9, pi = acos(-1);

inl int sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
inl int cmp(db x, db y) { return sign(x - y); }

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

inl void readP(P& p) { scanf("%lf %lf", &p.x, &p.y); }
inl db alpha(P p) { return atan2(p.y, p.x); }
inl db len2(P p) { return p.x*p.x + p.y*p.y; }
inl db len(P p) { return sqrt(len2(p)); }
inl db dist(P p, P q) { return len(q - p); }
inl P unit(P p) { return p / len(p); }
inl int quad(P p) { return sign(p.y) == 1 || sign(p.y) == 0 && sign(p.x) >= 0; }

inl P rot(P p, db a) {return P(p.x*cos(a)-p.y*sin(a), p.y*cos(a)+p.x*sin(a)); }
inl P rot90(P p) { return P(-p.y, p.x); }
inl db dot(P p, P q) { return p.x * q.x + p.y * q.y; }
inl db det(P p, P q) { return p.x * q.y + p.y * q.x; }
inl bool cmp(P p, P q) { return quad(p)<quad(q) || quad(p)==quad(q)&&sign(det(p,q))>0; }

inl db cross(P p1, P p2, P p3) { return det(p2-p1, p3-p1); }
inl int crossOp(P p1, P p2,P p3) { return sign(cross(p1, p2, p3)); }
inl bool isLL(P p1, P p2, P q1,P q2) { return sign(det(p2-p1, q2-q1)) != 0; }
inl bool ltl(P p1, P p2, P q1, P q2) {
	return sign(det(p2-p1,q2-q1))!=0 ? 0 : (crossOp(p1,p2,q1)==0 ? 2 : 1);
}
inl P genLL(P p1,P p2, P q1, P q2) {
    db s1 = cross(p1, q2, p2), s2 = cross(p1, p2, q2);
    return (s1*q2 + s2*q1) / (s1+s2);
}

inl bool isSS_strict(P p1, P p2, P q1, P q2) {
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

