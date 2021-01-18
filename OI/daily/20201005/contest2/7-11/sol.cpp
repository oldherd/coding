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

const int N = 1000;
int a[N], b[N], ch[N][2], dat[N], tot = 1, top = 1;

void build(int p, int lp, int rp) {
    int id = 0;
    rep(i,lp,rp) if(b[i] == a[top]) {id = i; break;}
    dat[p] = a[top];
    if(id-1 >= lp) {
        ++top;
        ch[p][0] = ++tot; build(tot, lp, id-1);
    }
    if(rp >= id+1) {
        ++top;
        ch[p][1] = ++tot; build(tot, id+1, rp);
    }
}
queue<int> q;
int stk[N], tt;
void bfs() {
    tt = 0;
    q.push(1);
    while(!q.empty()) {
        int p = q.front(); q.pop();
        stk[++tt] = dat[p];
        if(ch[p][1]) q.push(ch[p][0]);
        if(ch[p][0]) q.push(ch[p][1]);
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    cin >> n;
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) cin >> a[i];
    tot = 1;
    build(1,1,n);
    bfs();
    rep(i,1,n-1) cout << stk[i] << ' ';
    cout << stk[n];
    return 0;
}