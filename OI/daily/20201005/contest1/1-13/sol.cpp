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

const int N = 100;

int dat[N];
int insert(int p, int x) {
    if(dat[p] == -1) { dat[p] = x; return p; }
    if(x > dat[p]) return insert(p<<1, x);
    else return insert(p<<1|1, x);
}

queue<int> q;
int stk[N], top;
void bfs(int start) {
    top = 0;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        stk[++top] = dat[cur];
        if(~dat[cur<<1]) q.push(cur<<1);
        if(~dat[cur<<1|1]) q.push(cur<<1|1);
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    memset(dat, -1, sizeof(dat));
    int n, tmp;
    cin >> n;
    cin >> tmp;
    dat[1] = tmp;
    int mx = 1;
    rep(i,2,n) {
        cin >> tmp;
        int md = insert(1, tmp);
        mx = max(mx, md);
    }
    bfs(1);
    cout << stk[1];
    rep(i,2,top) cout << ' ' << stk[i];
    cout << endl;
    bool flg = true;
    rep(i,1,mx) if(dat[i] == -1) { flg = false; break; }
    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}