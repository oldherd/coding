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

const int N = 10010;
char str[N] , str2[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int len , a;
    scanf("%s" , str);
    len = strlen(str);
    bool flg = true;
    a = 0;
    if(len <= 4) {
        rep(i,0,len-1) {
            if(str[i] >= '0' && str[i] <= '9') a = (a<<3) + (a<<1) + (str[i]&15);
            else {
                flg = false; break;
            }
        }
    } else flg = false;
    if(a > 1000 || a < 1) flg = false;
    if(flg) printf("%d + " , a);
    else printf("? + ");
    bool flg2 = true; int b = 0;
    scanf("%s" , str); len = strlen(str);
    if(len <= 4) {
        rep(i,0,len-1) {
            if(str[i] >= '0' && str[i] <= '9') b = (b<<3) + (b<<1) + (str[i]&15);
            else {
                flg2 = false; break;
            }
        }
    } else flg2 = false;
    if(b > 1000 || b < 1) flg = false;
    if(flg2) printf("%d = " , b);
    else printf("? = ");
    bool flg3 = true;
    if(~scanf("%s" , str)) flg3 = false;
    // while(~scanf("%s" , str));
    if(flg && flg2 && flg3) printf("%d\n" , a + b);
    else printf("?\n");
    return 0;
}