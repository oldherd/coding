#include <iostream>
#include <cmath>
using namespace std;

#define db double
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
void readP(P &p) { cin >> p.x >> p.y; }
//void writeP(P &p) { cout << "(" <<  p.x << ',' << p.y << ")" << endl;}
inline db cross(P p1, P p2, P p3) { return det(p2-p1, p3-p1); }
inline int crossOP(P p1, P p2, P p3) { return sign(cross(p1, p2, p3)); }
inline bool isLL(P p1, P p2, P q1, P q2) {
	// db a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
	// return sign(a1+a2) != 0;
	return sign(det(p2-p1, q2-q1)) != 0;
}
inline P genLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(p1, p2, q1), a2 = -cross(p1, p2, q2);
	return (q1 * a2 + q2 * a1) / (a1 + a2);
}

int main() {
	int tests;
	cin >> tests;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(tests--) {
		P p1, p2, p3, p4;
		readP(p1);readP(p2);readP(p3);readP(p4);
		if(isLL(p1, p2, p3, p4)) {
			P pLL = genLL(p1, p2, p3, p4);
			cout << "POINT " << pLL.x << ' ' << pLL.y << endl;
		} else {
			if(crossOP(p3, p1, p2) == 0) {
				cout << "LINE" << endl;
			} else {
				cout << "NONE" << endl;
			}
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}