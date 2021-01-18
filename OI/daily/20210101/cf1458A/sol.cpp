#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

template <class T> inline T abs(T a) { return a > 0 ? a : -a; }

const int N = 200010;

ll a[N], b[N];

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= m; ++i) std::cin >> b[i];
    ll g = 0;
    for(int i = 2; i <= n; ++i) g = std::__gcd(g, abs(a[i] - a[i-1]));
    // std::cout << g << std::endl;
    for(int i = 1; i <= m; ++i) {
        std::cout << std::__gcd(g, a[1] + b[i]) << ' ';
    }
    std::cout << std::endl;
    return 0;
}
