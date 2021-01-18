#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)
 
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int,int> pii;
 
#define VI vector<int>
#define VD vector<db>
#define itra vector<int>::iterator
#define inl inline
 
const db eps = 1e-9;
 
inl void read(int &x) {
    char ch; x = 0; int f = 1;
    do{ ch=getchar(); if(ch=='-')f = -f; }while( ch < '0' || ch > '9' );
    do{ x = (x<<3) + (x<<1) + (ch&15); ch = getchar(); }while( ch >= '0' && ch <= '9' );
}
 
pii timeInc(pii preTime) {
    if(++preTime.second == 60) preTime.second = 0 , ++preTime.first;
    if(preTime.first == 12) preTime.first = 0;
    return preTime;
}
 
inl int sign(db x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
inl db angH(int h , int m) { return h * 30 + m / 2.0; }
inl db angM(int m) { return m * 6; }
inl int check(pii t) {
    return sign(angH(t.first , t.second) - angM(t.second));
}
 
void outTime(int data1 , int data2) {
    if(data1 < 10) cout << '0';
    cout << data1 << ':';
    if(data2 < 10) cout << '0';
    cout << data2;
}
 
int work(pii s , pii t) {
    int ans = 0;
    bool flg = true;
    if(s.first == 12) s.first = 0;
    if(t.first == 12) t.first = 0;
    // cout << t.first << ' ' << t.second << endl;
    // cout << s.first << ' ' << s.second << endl;
    while(s != t) {
        pii inced = timeInc(s);
        if(check(s) == 0 || s != t && check(s) > 0 && check(inced) < 0) {
            ++ans;
            // cout << endl << s.first << ' ' << s.second << ' ' << endl ;//<< inced.first << ' ' << inced.second << ' ' << check(s) << ' ' << check(inced) << endl;//只有时针超过分针的情况
            // cout << angH(s.first , s.second) << ' ' << angM(s.second) << endl;
            // cout << angH(inced.first , s.second) << ' ' << angM(inced.second) << endl;
        }
        s = inced;
    }
    return ans;
}
 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout << "Initial time  Final time  Passes" << endl;
    int s1 , s2 , t1 , t2;
    // cout << check(make_pair(12,50)) << ' ' << check(make_pair(12,51)) << endl;
    // cout << angH(12 , 50) << ' ' << angM(50) << endl;
    // cout << angH(12 , 51) << ' ' << angM(51) << endl;
    while(cin >> s1 >> s2 >> t1 >> t2) {
        cout << "       ";
        outTime(s1 , s2);
        cout << "       ";
        outTime(t1 , t2);
        cout << "      ";
        int ans = work(make_pair(s1 , s2) , make_pair(t1 , t2));
        if(ans > 9) cout << ans << endl;
        else cout << ' ' << ans << endl;
    }
    return 0;
}
