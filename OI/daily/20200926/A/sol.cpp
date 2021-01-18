#include <cstdio>
#include <iostream>
#include <vector>
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

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int a1 , a2 , b1 , b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 > b1 || a1 == b1 && a2 < b2) cout << "alice" << endl;
    else if(a1 == b1 && a2 == b2) cout << "oh" << endl;
    else cout << "bob" << endl;
    return 0;
}