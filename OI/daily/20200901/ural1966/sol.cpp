#include <bits/stdc++.h>

using namespace std;

typedef double db;
const db eps = 1e-9, pi = acos(-1);

int sign(double x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
int cmp(double x, double y) { return sign(x - y); }
struct P {
	db x, y;
	P() {}
	P(db X, db Y) : x(X), y(Y) {}
};
inline P operator + (P p1, P p2) { return P(p1.x + p2.x, p1.y + p2.y); }
inline P operator - (P p1, P p2) { return P(p1.x - p2.x, p1.y - p2.y); }
inline P operator * (P p, db o) { return P(p.x * o, p.y * o); }
inline P operator * (db o, P p) { return P(p.x * o, p.y * o); }
inline P operator / (P p, db o) { return P(p.x / o, p.y / o); }
inline int quad(P p) { return sign(p.y) == 1 || sign(p.y) == 0 && sign(p.x) == 1; }
inline db dot(P p1, P p2) { return p1.x * p2.x + p1.y * p2.y; }
inline db det(P p1, P p2) { return p1.x * p2.y - p1.y * p2.x; }
inline db abs2(P p) { return p.x * p.x + p.y * p.y; }
inline db abs(P p) { return sqrt(abs2(p)); }
inline db distTo(P p1, P p2) { return abs(p2 - p1); }
inline P unit(P p) { return p / abs(p); }
inline P rot90(P p) { return P(-p.y, p.x); }
inline P rot(P p, db a) { return P(p.x*cos(a)-p.y*sin(a), p.y*cos(a)+p.x*sin(a)); }
inline bool cmp(P p1, P p2) { 	//sort by atan
	return quad(p1) < quad(p2) || quad(p1) == quad(p2) && sign(det(p1, p2)) > 0;
}
inline void readP(P &p) { scanf("%lf %lf", &p.x, &p.y); }
inline db cross(P p1, P p2, P p3) { return det(p2-p1, p3-p1); }
inline int crossOp(P p1, P p2, P p3) { return sign(cross(p1, p2, p3)); }
inline bool isLL(P p1, P p2, P q1, P q2) {
	// db a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
	// return sign(a1+a2) != 0;
	return sign(det(p2-p1, q2-q1)) != 0;
}
inline P genLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
	return (q1 * a2 + q2 * a1) / (a1 + a2);
}
inline bool isPar(P p1, P p2, P q1, P q2) {
    return sign(det(p2-p1, q2-q1)) == 0 && crossOp(p1, p2, q1);
}
inline bool isLine(P p1, P p2, P q1, P q2) {
	return sign(det(p2-p1, q2-q1)) == 0 && crossOp(p1, p2, q1) == 0;
}
//Segment
inline bool intersect(db l1, db r1, db l2, db r2) {
    if(l1>r1) swap(l1, r1); if(l2>r2) swap(l2, r2);
    return sign(r1 - l2) > 0 || sign(r2 - l1) > 0;
}
inline bool isSS_strict(P p1, P p2, P q1, P q2) {
    return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1) * crossOp(q1,q2,p2) < 0;
}
inline bool isSS(P p1, P p2, P q1, P q2) {
    return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<=0 && crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<=0;
}
inline bool onSeg_strict(P p1, P p2, P q) {
	//return crossOp(p1,p2,q) == 0 && sign(dot(q-p1, p1-p2)) * sign(dot(q-p2, p1-p2)) < 0;
	return crossOp(p1,p2,q) == 0 && sign(dot(q-p1, q-p2)) < 0;
}
//inline bool isMid(db a, db m, db b) {
//	return sign(a-m) == 0 || sign(b-m) == 0 || ((a < m) != (b < m));
//}
//inline bool isMid(P a, P m, P b) {
//	return isMid(a.x, m.x, b.x) && isMid(a.y, m.y, b.y);
//}
inline bool onSeg(P q, P p1, P p2) {
	return crossOp(p1,p2,q) == 0 && sign(dot(q-p1,q-p2)) <= 0;
//	return crossOp(p1, p2, q) == 0 && isMid(p1, q, p2);
}

const int maxn = 2340;
P pt[maxn];	
int seg[maxn][2], par[maxn], inW[maxn];
int findf(int x) { return x == par[x] ? x : par[x] = findf(par[x]); }

int main() {
    int n, m, px, py;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) par[i] = i;
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &px, &py);
        pt[i].x = px; pt[i].y = py;
    }
    for(int i = 1; i <= m; ++i)
        scanf("%d %d", &seg[i][0], &seg[i][1]);
    for(int i = 1; i <= m; ++i)
        for(int j = i + 1; j <= m; ++j)
            if(findf(i) != findf(j) && isSS(pt[seg[i][0]], pt[seg[i][1]], pt[seg[j][0]], pt[seg[j][1]]))
                par[findf(i)] = j;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(onSeg(pt[i], pt[seg[j][0]], pt[seg[j][1]])) {
                inW[i] = findf(j);
                break;
            }
    bool flg = true;
    for(int i = 2; i <= n; ++i)
        if(inW[i] != inW[i-1]) {
            flg = false;
            break;
        }
    if(flg && inW[1]) printf("YES\n");
    else printf("NO\n");
    return 0;
}
