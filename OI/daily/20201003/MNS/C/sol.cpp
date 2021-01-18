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
char str[N][N];

bool check(int pls) {
    int len = strlen(str[pls]);
    return str[pls][len-2] == 'g' && str[pls][len-3] == 'n' && str[pls][len-4] == 'o';
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    scanf("%d" , &tests);
    while(tests--) {
        int top = 0;
        bool flg1 , flg2;
        while(true) {
            scanf("%s" , str[++top]);
            int len = strlen(str[top]);
            if(str[top][len-1] == ',') flg1 = check(top);
            if(str[top][len-1] == '.') {
                flg2 = check(top); break;
            }
        }
        if(flg1 && flg2) {
            // change(top);
            // rep(i,1,top-1) printf("%s " , str[i]);
            // printf("%s" , str[top]);
            rep(i,1,top-3) printf("%s " , str[i]);
            printf("qiao ben zhong.\n");
        } else {
            printf("Skipped\n");
        }
    }
    return 0;
}