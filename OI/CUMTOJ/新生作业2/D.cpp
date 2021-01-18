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
char str1[N] , str2[N];

int main() {
    scanf("%[^\n]s" , str1);
    getchar();
    scanf("%[^\n]s" , str2);
    int len1 = strlen(str1) , len2 = strlen(str2);
    int p1 = 0 , p2 = 0;
    while(p1 < len1 && p2 < len2) {
        while(p2 < len2 && str1[p1] != str2[p2]) ++p2;
        if(p2 < len2 && str1[p1] == str2[p2]) ++p1 , ++p2;
    }
    if(p1 == len1) printf("yes\n");
    else printf("no\n");
    return 0;
}