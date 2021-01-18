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

int num[15];
int idx[15];
int arr[15];


int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    string str;
    cin >> str;
    int len = str.length();
    cout << "int[] arr = new int[]{";
    rep(i,0,len-1) ++num[str[i]-'0'];
    int cnt = -1;
    per(i,9,0) {
        if(num[i]) {
            arr[++cnt] = i;
            idx[i] = cnt;
        }
    }
    cout << arr[0];
    rep(i,1,cnt) cout << "," << arr[i];
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    cout << idx[str[0]-'0'];
    rep(i,1,len-1) cout << ',' << idx[str[i]-'0'];
    cout << "};" << endl;
    // cout << "int[] arr = new int[]{8,3,2,1,0};\nint[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};";
    return 0;
}