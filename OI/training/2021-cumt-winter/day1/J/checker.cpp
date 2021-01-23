#include <bits/stdc++.h>

using namespace std;

int main() {
    system("g++ sol.cpp -std=c++11 -o sol");
    system("g++ brute.cpp -o brute -std=c++11");
    system("g++ gendata.cpp -o gendata -std=c++11");
    for(int i = 1; i <= 10000; ++i) {
        system("./gendata > data.in");
        system("./sol < data.in > data.out");
        system("./brute < data.in > data.ans");
        if(system("diff data.out data.ans")) {
            // printf("WA on %d.\n", i);
            cout << "WA" << i << endl;
            break;
        }
        cout << "AC" << i << endl;
    }
    return 0;
}
