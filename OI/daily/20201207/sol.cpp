#include <bits/stdc++.h>

namespace SA {
    const int Itime = 10000;
    const double alpha = 0.85;
    int T;
    void init() {
        srand((unsigned)time(NULL));

    }
    inline int rnd_int(int m) { return rand() * rand() % m; }
    inline double rnd_db() { return rnd_int(10000000) / 10000000; }
    inline double rand_bet(double l, double r) { return (r - l) * rnd_db() + l; }
    inline double f(double x) {
        return - x * x - 4 * x - 1 + 4;
    }
    double sa(double l, double r) {
        double x = rand_bet(l, r), nex_x = 0, delta = 0;
        for(int i = 0; i < Itime && T > 1e-7; ++i) {
            nex_x = rand_bet(l, r);
            delta = f(x) - f(nex_x);
            if(delta < 0) x = nex_x;
            else if(exp(delta/T) > rand_bet(0,1)) {
                x = nex_x;
                T *= alpha;
            }
        }
        return x;
    }
    inline double work(double l, double r) {
        return f(sa(l, r));
    }
}

int main() {
    double l, r;
    std::cin >> l >> r;
    SA::init();
    std::cout << SA::sa(l, r) << std::endl;
    return 0;
}