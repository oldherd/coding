#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)
#define pii pair<int,int>
#define itra multiset< pii >::iterator

using namespace std;

typedef double db;
typedef unsigned long long ull;

const int N = 100010, inf = 1e9+7;

multiset< pii > v[N];
map<int,int> h;
int f[N];

int main() {
    int n, q, x, xx, y;
    cin >> n >> q;
    char op[5];
    for(int i = 1; i <= n; ++i) f[i] = i;
    while(q--) {
        scanf("%s %d %d %d", op, &x, &xx, &y);
        if(op[0] == '+') v[y].insert(make_pair(x,xx)), ++h[y];
        else {
            itra it = v[y].find(make_pair(x,xx));
            v[y].erase(it);
            if(--h[y] == 0) {
                map<int,int>::iterator itr = h.find(y);
                h.erase(itr);
            }
        }
        for(map<int,int>::iterator it = h.begin(); it != h.end(); ++it) {
            for(itra itr = v[it->first].begin(); itr != v[it->first].end(); ++itr)
                swap(f[itr->first], f[itr->second]);
        }
        ull ans = 0;
        for(int i = 1; i <= n; ++i) ans += (ull)i * f[i];
        printf("%llu\n", ans);
        for(map<int,int>::reverse_iterator it = h.rbegin(); it != h.rend(); ++it) {
            for(multiset< pii >::reverse_iterator itr = v[it->first].rbegin(); itr != v[it->first].rend(); ++itr)
                swap(f[itr->first], f[itr->second]);
        }
    }
    return 0;
}
