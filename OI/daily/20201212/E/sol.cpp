#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

const int maxn = 200010;
int a[maxn], s[maxn];

template <typename T> void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

int main() {
    int d, p1, p2;
cin >> d >> p1 >> p2;
for(int i = 0; i < d; ++i)
    for(int j = 0; j < d; ++j)
        for(int k = 0; k < d; ++k) 
            cout << d * i + j + p1 << ' ' << d * j + k + p2 << endl;
    // int n, m;
    // rd(n);
    // rep(i,1,n) rd(a[i]);
    // rep(i,1,n) s[i] = a[i] + s[i-1];
    // rd(m);
    // rep(tests,1,m) {
    //     unsigned ans = 0;
    //     int d, p1, p2;
    //     rd(d); rd(p1); rd(p2);
    //     int t = d * d + p1 - 1, tt = d * d + p2 - 1;
    //     int j = p2;
    //     rep(i,p1,t) {
    //         if(j + d - 1 <= tt) ans += a[i] * (s[j+d-1] - s[j-1]), j = j + d;
    //         else ans += a[i] * (s[tt]-s[j-1]+s[1+j+d-tt]), j = j + d - tt + 2;
    //         if(j > tt) j = p2;
    //     }
    //     wr(ans); putchar('\n');
    // }
    return 0;
}