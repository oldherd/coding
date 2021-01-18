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

const int N = 110;
char mp[N][N];
char ans[N][N];

int n , m;

bool chkLeagel(int x , int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

int dx[] = {-1,-1,-1,0,0,1,1,1,} , dy[] = {-1,0,1,-1,1,-1,0,1};

int main() {
    int test = 0;
    while(~scanf("%d %d" , &n , &m) && n && m) {
        rep(i,1,n) scanf("%s" , mp[i] + 1);
        memset(ans , 0 , sizeof(ans));
        rep(i,1,n)
            rep(j,1,m)
                if(mp[i][j] == '*') ans[i][j] = '*';
                else {
                    int tmp = 0;
                    rep(k,0,7) {
                        if(chkLeagel(i + dx[k] , j + dy[k]) && mp[dx[k]+i][dy[k]+j]=='*') ++tmp;
                    }
                    ans[i][j] = tmp + '0';
                }
        if(++test != 1) printf("\n");
        printf("Field #%d:\n" , test);
        rep(i,1,n) printf("%s\n" , ans[i] + 1);
    }
    return 0;
}