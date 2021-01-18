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

const int maxn = 50010;
int Prime[maxn], vp[maxn], top;
void seive() {
    top = 0;
    for(int i = 2; i <= 40000; ++i) {
        if(!vp[i]) Prime[++top] = i;
        for(int j = 1; i * Prime[j] <= 40000; ++j) {
            vp[i * Prime[j]] = 1;
            if(!(i % Prime[j])) break;
        }
    }
}

bool isPrime(int k) {
    if(k <= Prime[top]) return !vp[k];
    int sqr = sqrt(k);
    for(int i = 1; Prime[i] < sqr; ++i) {
        if(!(k % Prime[i])) return false;
    }
    return true;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); 
    seive();
    // for(int i =  1; i <= top; ++i) printf("%d ", Prime[i]);
    // printf("\n%d\n", top);
    int tests;
    cin >> tests;
    while(tests--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if(r - l + 1 > 100) printf("Yes\n");
        else {
            int cnt = 0;
            for(int i = l; i <= r; ++i) {
                if(isPrime(i)) ++cnt;
            }
            if(3 * cnt < (r - l + 1)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}