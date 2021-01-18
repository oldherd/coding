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

priority_queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        int n, tmp;
        cin >> n;
        rep(i,1,n) {
            cin >> tmp;
            q.push(tmp);
        }
        bool flg = true;
        while(!q.empty()) {
            if(q.size() >= 2) {
                int r = q.top(); q.pop();
                int l = q.top(); q.pop();
                --r; --l;
                if(r) q.push(r);
                if(l) q.push(l);
            } else if(q.size() == 1) {
                cout << "T\n"; flg = false;
                q.pop();
            }
        }
        if(flg) cout << "HL\n";
    }
    return 0;
}
