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

const int N = 1000100;
int buc[N];
int tmp;
inline void read() {
    tmp = 0; char ch;
    do{ ch = getchar(); }while(ch < '0' || ch > '9');
    do{ tmp = (tmp<<3) + (tmp << 1) + (ch&15); ch = getchar(); } while(ch >= '0' && ch <= '9');
}

int main() {
    int k, n;
    read(); n = tmp;
    read(); k = tmp;
    int top = 0;
    rep(i,1,n) {
        read();
        ++buc[tmp];
        top = max(top, tmp);
    }
    int ans = 1 , cnt;
    rep(i,2,top) {
        cnt = 0;
        // cout << i << endl;
        for(int j = i; j <= top; j += i) {
            // cout << buc[j] << ' '; 
            cnt += buc[j];
            if(cnt >= k) break;
        }
        // cout << endl;
        if(cnt >= k) ans = i;
    }
    cout << ans << endl;
    return 0;
}