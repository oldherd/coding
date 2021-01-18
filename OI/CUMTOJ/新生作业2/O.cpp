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

char str[N];
int len;

void outHead(int s , int dig) {
    rep(i,0,len-1) {
        putchar(' ');
        if(str[i] != '1' && str[i] != '4') rep(j,1,s) putchar('-');
        putchar(' ');
    }
}

void outMid(int s) {
    rep(i,0,len-1) {
        putchar(' ');
        if(str[i] != '1' && str[i] != '4') rep(j,1,s) putchar('-');
        putchar(' ');
    }
}

void 

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int s , n;
    while(~scanf("%d" , &s)) {
        memset(str , 0 , sizeof(str));
        scanf("%[^\n]s" , str);
        if(s == 0 && str[0] == '0') break; 
        len = strlen(str);
        rep(i,0,len-1)
            outHead(s , str[i]-'0');
            rep(i,1,s) outLHigh();
            outMid(s);
            rep() outLLow();
            outBot(s);
    }

    return 0;
}