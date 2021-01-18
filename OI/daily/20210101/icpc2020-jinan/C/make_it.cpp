#include <bits/stdc++.h>

using namespace std;

char str[1000];

int main() {
    ifstream in("sol.cpp", ios::in);
    ofstream out("out.cpp", ios::out);
    while(in.getline(str, 1000)) {
      out << '\"' << str << "\" \\n" << endl;
    }
    return 0;
}
