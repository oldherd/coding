#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)

using namespace std;

typedef long long ll;
typedef double db;
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
int mon[N];

int main() {
    int n;
    while(~scanf("%d" , &n) && n) {
        db tmp;
        int sum = 0;
        rep(i,1,n) {
            scanf("%lf" , &tmp);
            sum += (mon[i] = (int)(tmp * 100 + 0.5));
        }
        sort(mon + 1 , mon + n + 1);
        int low = n - (sum - sum / n * n);
        // printf("##########");
        // printf("\n%d %d\n" , low , sum / n);
        int ans = 0;
        rep(i,1,low) ans = ans + abs(mon[i] - sum / n);
        rep(i,low+1,n) ans = ans + abs(mon[i] - sum / n - 1);
        ans /= 2;
        printf("$%d." , ans / 100);
        ans %= 100;
        if(ans < 10) printf("0%d\n" , ans);
        else printf("%d\n" , ans);
    }
    return 0;
}