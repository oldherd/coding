#include <bits/stdc++.h>

using namespace std;

int main() {
    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    if(n <= k) cout << 2 << endl;
    else cout << ((n * 2 / k) + ((n * 2) % k ? 1 : 0)) << endl;
    return 0;
}
