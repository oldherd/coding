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

const int N = 25 , L = 4010;

char badWord[N][L] , excuse[N][L];
int matched[N];

bool sameChar(char a , char b) {
    return a == b || a + 'A' - 'a' == b || a - 'A' + 'a' == b;
}

bool match(char mode[] , char para[]) {
    int len1 = strlen(mode) , len2 = strlen(para);
    for(int i = 0 ; i + len1 - 1 < len2 ; ++i) {
        int p;
        for(p = 0 ; p < len1 && sameChar(mode[p] , para[i + p]) ; ++p);
        if(p == len1) return true;
    }
    return false;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n , m;
    while(~scanf("%d %d" , &n , &m)) {
        memset(matched , 0 , sizeof(matched));
        rep(i,1,m) scanf("%s" , badWord[i]);
        rep(i,1,n) scanf("%s" , excuse[i]);
        rep(i,1,n)
            rep(j,1,m) {
                if(match(&badWord[j][0] , &excuse[i][0])) ++matched[i];
            }
        int ans = 1;
        rep(i,2,n) if(matched[i] > matched[ans]) ans = i;
        // rep(i,1,n) cout << matched[i] << ' ';
        // cout << endl;
        printf("%s\n" , excuse[ans]);
    }
    return 0;
}