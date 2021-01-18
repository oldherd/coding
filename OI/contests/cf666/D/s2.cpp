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

const int inf = 10000;
multiset<int> hi;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    cin >> tests;
	hi.insert(inf);
       hi.insert(-inf);
    while(tests--) {
        int n, tmp;
        cin >> n;
        rep(i,1,n) {
            cin >> tmp;
            hi.insert(tmp);
        }
        bool flg = true;
        while(hi.size() > 2) {
            multiset<int>::iterator it1 = hi.find(-inf), it2 = hi.find(inf);
            if(hi.size() == 3) {
                flg = false;
                hi.erase(++it1);
                cout << "T\n";
            } else {
                ++it1, --it2;
                if(*it1 == *it2) {
                    hi.erase(it2);
                    hi.erase(it1);
                } else {
                    int t = *it2 - *it1;
                    hi.erase(it2);
                    hi.erase(it1);
                    hi.insert(t);
                }
            }
        }
        if(flg) cout << "HL\n";
    }
    return 0;
}
