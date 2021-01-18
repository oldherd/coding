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

const int N = 2010;
char str[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    scanf("%[^\n]s" , str);
    int len = strlen(str) , cnt = 0;
    repp(i,0,len) {
        if(str[i] == '6') ++cnt;
        else {
            if(cnt > 3 && cnt <= 9) {
                putchar('9');
            } else if(cnt > 9) {
                putchar('2'); putchar('7');
            } else {
                rep(i,1,cnt) putchar('6');
            }
            putchar(str[i]);
            cnt = 0;
        }
    }
    if(cnt) {
        if(cnt <= 3) rep(i,1,cnt) putchar('6');
        else if(cnt > 3 && cnt <= 9) putchar('9');
        else putchar('2') , putchar('7');
    }
    return 0;
}