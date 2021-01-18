// #include <bits/stdc++.h>
// #define rep(i,a,b) for(int i=(a);i<=(b);++i)
// #define per(i,a,b) for(int i=(a);i>=(b);--i)
// #define repp(i,a,b) for(int i=(a);i<(b);++i)
// #define perr(i,a,b) for(int i=(b);i>(a);--i)

// using namespace std;

// typedef long long ll;
// typedef pair<int,int> pii;
// typedef vector<int> VI;
// typedef vector<long long> VL;
// typedef vector<double> VD;
// typedef vector<int>::iterator itra;

// const int maxn = 300010 , inf = 1100000000;
// int a[maxn] , datMin[maxn] , datMax[maxn];
// void build(int p , int lp , int rp) {
//     if(lp == rp) {
//         datMin[p] = a[lp];
//         datMax[p] = a[lp];
//         return;
//     }
//     int mid = (lp + rp) >> 1;
//     build(p<<1 , lp , mid);
//     build(p<<1|1 , mid + 1, rp);
//     datMin[p] = min(datMin[p<<1] , datMin[p<<1|1]);
//     datMax[p] = max(datMax[p<<1] , datMax[p<<1|1]);
// }
// int queryMin(int p , int lp , int rp , int l , int r) {
//     if(l <= lp && rp <= r) return datMin[p];
//     int mid = (lp + rp) >> 1;
//     int ans = inf;
//     if(l <= mid) ans = queryMin(p<<1 , lp , mid , l , r);
//     if(r > mid) ans = min(ans , queryMin(p<<1|1 , mid + 1 , rp , l , r));
//     return ans;
// }

// int queryMax(int p , int lp , int rp , int l , int r) {
//     if(l <= lp && rp <= r) return datMax[p];
//     int mid = (lp + rp) >> 1;
//     int ans = 0;
//     if(l <= mid) ans = queryMax(p<<1 , lp , mid , l , r);
//     if(r > mid) ans = max(ans , queryMax(p<<1|1 , mid + 1 , rp , l , r));
//     return ans;
// }

// int f[maxn] , n;

// bool check(int l , int r) {
//     if(r == l + 1) return true;
//     if(queryMax(1 , 1 , n , l + 1 , r - 1) < min(a[l] , a[r])) return true;
//     if(queryMin(1 , 1 , n , l + 1 , r - 1) > max(a[l] , a[r])) return true;
//     return false;
// }

// int main() {
// //	ios_base::sync_with_stdio(false);
// //	cin.tie(NULL);
//     scanf("%d" , &n);
//     for(int i = 1; i <= n; ++i) scanf("%d", a + i);
//     build(1 , 1 , n);
//     int l = 1;
//     for(int i = 2; i <= n; ++i) {
//         while(!check(l , i))
// 			++l;
//         f[i] = f[l] + 1;
//     }
//     printf("%d\n" , f[n]);
//     return 0;
// }


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

const int maxn = 300010 , inf = 1000000010;

const int maxn = 300010 , inf = 1100000000;
int a[maxn] , datMin[maxn] , datMax[maxn];
void build(int p , int lp , int rp) {
    if(lp == rp) {
        datMin[p] = a[lp];
        datMax[p] = a[lp];
        return;
    }
    int mid = (lp + rp) >> 1;
    build(p<<1 , lp , mid);
    build(p<<1|1 , mid + 1, rp);
    datMin[p] = min(datMin[p<<1] , datMin[p<<1|1]);
    datMax[p] = max(datMax[p<<1] , datMax[p<<1|1]);
}
int queryMin(int p , int lp , int rp , int l , int r) {
    if(l <= lp && rp <= r) return datMin[p];
    int mid = (lp + rp) >> 1;
    int ans = inf;
    if(l <= mid) ans = queryMin(p<<1 , lp , mid , l , r);
    if(r > mid) ans = min(ans , queryMin(p<<1|1 , mid + 1 , rp , l , r));
    return ans;
}

int queryMax(int p , int lp , int rp , int l , int r) {
    if(l <= lp && rp <= r) return datMax[p];
    int mid = (lp + rp) >> 1;
    int ans = 0;
    if(l <= mid) ans = queryMax(p<<1 , lp , mid , l , r);
    if(r > mid) ans = max(ans , queryMax(p<<1|1 , mid + 1 , rp , l , r));
    return ans;
}

bool check(int l , int r) {
    if(r == l + 1) return true;
    if(queryMax(1 , 1 , n , l + 1 , r - 1) < min(a[l] , a[r])) return true;
    if(queryMin(1 , 1 , n , l + 1 , r - 1) > max(a[l] , a[r])) return true;
    return false;
}

int dis[maxn];
queue<int> q;
void bfs() {
    q.push(1); dis[q] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = cur + 1)
        for(int i = cur - 1; i > 1; --i) if
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    int n;
    scanf("%d" , &n);
    for(int i = 1; i <= n; ++i) scanf("%d" , a + i);
    bfs();
    printf("%d\n" , dis[n]);
    return 0;
}