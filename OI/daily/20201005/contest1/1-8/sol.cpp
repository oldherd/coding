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

const int N = 1000010;
char str[N];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    char tk[3];
    scanf("%d ", &n);
    scanf("%s" , tk);
    getchar();
    scanf("%[^\n]s" , str);
    int len = strlen(str);
    if(len == n) printf("%s" , str);
    else if(len < n) {
        int ts = n - len;
        rep(i,1,ts) putchar(tk[0]);
        printf("%s" , str);
    } else {
        printf("%s" , &str[len-n]);
    }
    // printf("\n____I love GPLT\n");
    // printf("\n cut\n");
    return 0;
}