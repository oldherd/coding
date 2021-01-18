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

const int N = 1234;
char str[N] , ans[N];
const char* canyou = "can you" , *couldyou = "could you" , *ican = "I can" , *icould = "I could";

bool checkCanYou(int i) {
    rep(j,0,6) if(str[i+j] != canyou[j]) return false;
    return true;
}

bool checkCouldYou(int i) {
    rep(j,0,8) if(str[i+j] != couldyou[j]) return false;
    return true;
}
void add1(int top) {
    rep(j,0,4) str[++top] = ican[j];
}
void add2(int top) {
    rep(j,0,6) str[++top] = icould[j];
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    scanf("%d" , &n);
    getchar();
    rep(test,1,n) {
        scanf("%[^\n]s" , str);
        getchar();
        int cnt = 0 , top = -1;
        int len = strlen(str);
        repp(i,0,len) if(str[i] >= 'A' && str[i] <= 'Z' && str[i] != 'I') str[i] = str[i] - 'A' + 'a';
        for(int i = 0; i < len; ++i) {
            if(str[i] == ' ') ++cnt;
            else {
                if(cnt > 0 && (str[i] >= 'a' && str[i] <= 'z')) ans[++top] = ' ';
                ans[++top] = str[i];
                cnt = 0;
            }
        }
        memcpy(str , ans , sizeof(ans));
        top = -1;
        for(int i = 0; i < len; ++i) {
                if(str[i] == '?') ans[++top] = '!';
                else if(str[i] == 'c') {
                    int dis = 0;
                    if(checkCanYou(i)) add1(top) , dis += 6; ////
                    else if(checkCouldYou(i)) add2(top) , dis += 8;
                    else ans[++top] = 'c';
                    i += dis;//////
                } else if(str[i] == 'I') {
                    ans[++top] = 'y', ans[++top] = 'o' , ans[++top] = 'u';
                }else if(str[i] == 'm' && str[i+1] == 'e') ans[++top] = 'y', ans[++top] = 'o' , ans[++top] = 'u' , ++i;
                else ans[++top] = str[i];
        }
        printf("AI: %s\n" , ans);
    }
    return 0;
}