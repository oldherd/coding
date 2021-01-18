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

const int maxn = 1000010;

int trie[maxn][2];
ll cnt[maxn], sum[maxn], tot;

void insert(char[] str, int len, int v) {
    int p = 1; sum[p] += v;
    for(int i = 0; i < len; ++i) {
        int f = str[i] - '0';
        if(!trie[p][f]) trie[p][f] = ++tot;
        p = trie[p][f];
        sum[p] += v;
    }
    cnt[p] += v;
}

int list[50], t;
bool del(int p, int depth, char str[], int len) {
    int p = 1, t = 0; list[0] = 1;
    for(int i = 0; i < len; ++i) {
        int f = str[i] - '0';
        if(!trie[p][f]) return false;
        p = trie[p][f]; list[++t] = p;
    }
    for(int i = 0; i <= t; ++i) sum[list[i]] -= cnt[p];
    cnt[p] = 0;
    return true;
}

ll qry(char str[], int len) {
    int p = 0;
    for(int i = 0; i < len; ++i) {
        int f = str[i] - '0';
        if(!trie[p][f]) return 0;
        p = trie[p][f];
    }
    return sum[p];
}

bool cgpre(char str[], int len, char str2[], int len2) {
    int p = 1, t = 0; list[0] = 1;
    for(int i = 0; i < len; ++i) {
        int f = str[i] - '0';
        if(!trie[p][f]) return false;
        p = trie[p][f]; list[++t] = p;
    }
    for(int i = 0; i < t; ++i) sum[list[i]] -= sum[p];
    int p2 = 1; sum[p2] += sum[p];
    for(int i = 0; i < len; ++i) {
        int f = str[i] - '0';
        if(!trie[p2][f]) trie[p2][f] = ++tot;
        p2 = trie[p2][f];
        sum[p2] += sum[p];
    }
    merge();
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int tests;
    scanf("%d", &tests);
    for(__  = 1; __ <= tests; __++) {
        printf("Case %d\n", __);
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        int n, v;
        char op[2], str[15], str2[15];
        scanf("%d", &n);
        tot = 0;
        while(n--) {
            scanf("%s", str);
            int len = strlen(str);
            if(op[0] == 'I') {
                scanf("%d", &v);
                insert(str, len, v);
            } else if(op[1] == 'D') {
                if(!del(1, 0, str, len))
                    printf("Not Exist\n");
            } else if(op[2] == 'Q') {
                printf("%lld", qry(str, len));
            } else if(op[3] == 'U') {
                scanf("%s", str2);
                int len2 = strlen(str2);
                if(!cgpre(str, len, str2, len2)) {
                    printf("Not Exist\n");
                }
            }
        }
    }
    return 0;
}