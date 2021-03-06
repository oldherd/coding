/*
  sol.cpp -- 8 digits
*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)
#define pb push_back
#define rz resize

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<ldb> VD;

inline int genpls(string s) {
    for(int i = 0; i < 9; ++i) if(s[i] == 'X') return i;
    return -1;
}

const int d[] = {3, -1, 1, -3};
const string ts[] = {"d", "l", "r", "u"};
int ans[10][400010];
int fac[10];

inline int tovec(int *v, int num) {
    int ret = -1, used[9] = {0};
    rep(i,0,8) {
        int res = num / fac[8-i];
        rep(j,0,8) {
            if(used[j]) continue;
            if(!res) {
                used[j] = 1;
                v[i] = j;
                break;
            }
            --res;
        }
        num %= fac[8-i];
        if(v[i] == 0) ret = i;
    }
    return ret;
}

inline int toint( int *v ) {
    int used[9] = {0}, ret = 0;
    rep(i,0,8) {
        int t = v[i];
        repp(j,0,v[i]) t -= used[j];
        ret += t * fac[8-i];
        used[v[i]] = 1;
    }
    return ret;
}

queue<int> q;
int counter = 0;
void bfs(int *svec, int pls) {
    auto& mp = ans[pls];
    int sint = toint(svec);
    q.push(sint); mp[sint] = -2;
    int curvec[9];
    while(!q.empty()) {
        int curint = q.front(); q.pop();
        int pls = tovec(curvec, curint);
        repp(i,0,4) {
            if(pls%3==2 && i==2) continue;
            if(pls%3==0 && i==1) continue;
            int to = pls + d[i];
            if(to > -1 && to < 9) {
                swap(curvec[to], curvec[pls]);
                int nexint = toint(curvec);
                if(!(~mp[nexint])) {
                    q.push(nexint);
                    mp[nexint] = i;
                }
                swap(curvec[to], curvec[pls]);
            }
        }
    }

}

void prework() {
    int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    memset(ans, -1, sizeof(ans));
    bfs(a, 0);
    rep(i,0,7) {
        swap(a[i], a[i+1]);
        bfs(a, i+1);
    }
}

int main() {
    // if(fopen("yl.in", "r")) {
    //     freopen("yl.in", "r", stdin);
    //     freopen("yl.out", "w", stdout);
    // }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        fac[0] = fac[1] = 1;
    rep(i,2,9) fac[i] = fac[i-1] * i;
    prework();
    int tests = 1;
    cin >> tests;
    char str[10];
    int svec[9], tvec[9], revec[15];
    string answer;
    rep(test,1,tests) {
        memset(revec, 0, sizeof(revec));
        cin >> str;
        int typ, cnter = 0;
        rep(i,0,8) {
            if(str[i] == 'X') svec[i] = 0, typ = i;
            else svec[i] = str[i] - '0', revec[svec[i]] = ++cnter, svec[i] = cnter;
        }
        cin >> str;
        rep(i,0,8) {
            if(str[i] == 'X') tvec[i] = 0;
            else tvec[i] = str[i] - '0';
            tvec[i] = revec[tvec[i]];
        }
        int cur = toint(tvec), sint = toint(svec);
        int curvec[9];
        answer.clear();
        while(cur != sint) {
            answer = ts[ans[typ][cur]] + answer;
            int pls = tovec(curvec, cur);
            swap(curvec[pls], curvec[-d[ans[typ][cur]] + pls]);
            cur = toint(curvec);
        }
        cout << "Case " << test << ": " << answer.length() << '\n' << answer << '\n';
    }
    return 0;
}
