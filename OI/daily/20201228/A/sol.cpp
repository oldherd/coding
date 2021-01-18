#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(a);i>(b);--i)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int N = 110;
char str[N];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    int tests;
    cin >> tests;
    while(tests--) {
        cin >> str;
        int len = strlen(str);
        if(len % 2) {
        	cout << "NO\n";
			continue; 
       	}
       	if(str[0] == ')' || str[len-1] == '(') {
       		cout  << "NO\n";	
       	} else {
       		cout << "YES\n";	
       	}
//        bool flg = false;
//        int t = 0;
//        for(int i = 0; i < len; ++i) {
//            if(str[i] == '(') {
//                if(flg) {
//                    int tt = i - t + 1;
//                    if(tt % 2 == 0 && (len-i) % 2 == 0) {
//                        cout << "YES\n";
//                    } else {
//                        cout << "NO\n";
//                    }
//                    break;
//                } else {
//                    flg = true;
//                    t = i;
//                    if(i % 2 != 0) {
//                        cout << "NO\n";
//                        break;
//                    }
//                }
//            } else if(str[i] == '(') {
//                if(flg) {
//                    int tt = i - t + 1;
//                    if(tt % 2 == 0 && (len-i) % 2 != 0) {
//                        cout << "YES\n";
//                    } else cout << "NO\n";
//                    break;
//                } else {
//                    flg = true;
//                    t = i;
//                }
//            }
//        }
    }
    return 0;
}
