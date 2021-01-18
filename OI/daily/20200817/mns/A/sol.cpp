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

inline void read(int &x) {
    char ch; int f = 1; x=0;
    do{ch=getchar();if(ch=='-')f=-f;}while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}while(ch>='0'&&ch<='9');
    x *= f;
}

const int Mod = 1000000007;

inline int Inc(int a, int b){
    return (a += b) >= Mod ? a - Mod : a;
}
inline int Dec(int a, int b){
    return (a -= b) < 0 ? a + Mod : a;
}
inline int Mul(int a, int b){
    return 1ll * a * b % Mod;
}

const int maxn = 2000010;
int f[maxn], p[maxn], n;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    read(n);
    rep(i,1,n) read(p[i]);
    f[1] = 2;
    // rep(i,2,n) f[i] = 2 * f[i - 1] - f[p[i] - 1] + 2;
    rep(i,2,n) f[i] = Inc(Dec(Mul(2, f[i - 1]), f[p[i] - 1]), 2);
    printf("%d\n", f[n]);
    return 0;
}