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

const int N = 100010;

char str[N];
int a[N], s[N], datMin[N], datMax[N], datSum[N];
void build(int p, int lp, int rp) {
    if(lp == rp) {
        datMin[p] = datMax[p] = s[lp];
        datSum[p] = a[lp];
        return;
    }
    int mid = lp + rp >> 1;
    build(p<<1,lp,mid); build(p<<1|1,mid+1,rp);
    update(p);
}

void changeSum(int p, int lp, int rp, int l, int r, int v) {
    if(l <= lp && rp <= r) {
        tagSum[p] += v; datSum[p] += (rp-lp+1) * v;
        return;
    }
    int mid = lp + rp >> 1;
    if(tagSum[p]) pushdownSum(p);
    changeSum(p<<1,lp,mid,l,r,v);
    changeSum(p<<1|1,mid+1,rp,l,r,v);
    updateSum(p);
}

void changeMinMax(int p, int lp, int rp, int l, int v) {
    if(l <= lp && rp <= r) {
        tagMinMax[p] += v; datMin[p] += (rp-lp+1) * v; datMax[p] += (rp-lp+1)
        return;
    }
    int mid = lp + rp >> 1;
    if(tagSum[p]) pushdownSum(p);
    changeSum(p<<1,lp,mid,l,r,v);
    changeSum(p<<1|1,mid+1,rp,l,r,v);
    updateSum(p);
}

int main() {
    int n, m;
    cin >> n >> m;
    cin >> str + 1;
    rep(i,1,n) a[i] = str[i]=='('?1:-1, s[i] = s[i-1] + a[i];
    return 0;
}