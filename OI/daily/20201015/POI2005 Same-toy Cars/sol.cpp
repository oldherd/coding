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

struct node {
    int id, pls;
    node() {}
    node(int id, int pls) : id(id), pls(pls) {}
    bool operator < (const node& o) const {
    	return pls < o.pls || pls == o.pls && id < o.id;
    }
};
 
vector< vector<int> > v;
const int N = 100010, P = 500010;
int a[P], ink[N], nex[N];

priority_queue< node > q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k, p;
    cin >> n >> k >> p;
    v.resize(n + 1);
    rep(i,1,p) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    rep(i,1,n) v[i].push_back(p+1);
    int ans = 0, realSize = 0;
    rep(i,1,n) nex[i] = 0;
    rep(i,1,p) {
        int tar = a[i]; ++nex[tar];
        if(!ink[tar]) {
            if(realSize == k) {
                node cur = q.top();
                while(cur.id == tar || cur.pls != v[cur.id][nex[cur.id]]) q.pop(), cur = q.top();
                --realSize; ink[cur.id] = 0; q.pop();
            }
            ink[tar] = 1; ++ans; ++realSize;
        }
        q.push(node(tar, v[tar][nex[tar]]));
    }
    cout << ans << endl;
    return 0;
}
