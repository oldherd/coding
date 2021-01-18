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

inline void read(int &tmp) {
    tmp = 0; char ch;
    do{ ch = getchar(); }while(ch < '0' || ch > '9');
    do{ tmp = (tmp<<3) + (tmp << 1) + (ch&15); ch = getchar(); } while(ch >= '0' && ch <= '9');
}

const int N = 100010;
int a[N];

struct node{
    int h , id;
    node() {}
    node(int h , int id) : h(h) , id(id) {}
};

deque<node> q;
int lh[N] , rh[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    read(n);
    if(n == 2) {
        printf("0\n");
        return 0;
    }
    rep(i,1,n) read(a[i]);
    q.push_back( node(a[1] , 1) );
    rep(i,2,n-1) {
        while(!q.empty() && q.back().h <= a[i]) q.pop_back();
        if(q.empty()) {
            lh[i] = -1;
        } else {
            lh[i] = q.back().id;
        }
        q.push_back(node(a[i] , i));
    }
    q.clear(); q.push_back(node(a[n] , n));
    per(i,n-1,2) {
        while(!q.empty() && q.back().h <= a[i]) q.pop_back();
        if(q.empty()) {
            rh[i] = -1;
        } else {
            rh[i] = q.back().id;
        }
        q.push_back(node(a[i] , i));
    }
    int ans = 0;
    rep(i,2,n-1) {
        if(~lh[i] && ~rh[i]) ans = max(ans , rh[i] - lh[i] - 1);
        // printf("(%d,%d) " , lh[i] , rh[i]);
    }
    printf("%d\n" , ans);
    return 0;
}