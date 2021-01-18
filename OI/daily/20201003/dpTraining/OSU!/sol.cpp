#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

typedef double db;

int main() {
    int n;
    db a = 0 , b = 0 , f = 0 , p;
    cin >> n;
    rep(i,1,n) {
        cin >> p;
        f += (3 * b + 3 * a + 1) * p;
        b = (b + 2 * a + 1) * p;
        a = (a + 1) * p;
    }
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << f << endl;
    return 0;
}