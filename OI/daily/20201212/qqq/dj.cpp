#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repp(i,a,b) for(int i=(a);i<(b);++i)
#define perr(i,a,b) for(int i=(b);i>(a);--i)
#define re register int
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<int>::iterator itra;

const int maxn = 550;
int a[maxn], ans[maxn][maxn],t[maxn],op[3];
vector<int> awa,tag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    rep(i,1,m) cin >> a[i];
    bool flg = true;
    if(n % 2 == 0) {
        rep(i,1,m) if(a[i] > n / 2) {
            flg = false;
             break;
        }
        if(!flg) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            rep(i,1,m) {
                for(int j = i % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;
            }
            rep(i,1,n) {
                rep(j,1,m) cout << ans[i][j];
                cout << endl;
            }
        }
        return 0;
    } else {
        rep(i,1,m) {
            if(a[i] > n / 2 + 1) {
                flg = false;
                break;
            }
            if(a[i] == n / 2 + 1) t[i] = 1,awa.push_back(i),op[i%2]=1;
        }
        rep(i,2,m) if(t[i]&&t[i-1]) flg=0;
        int qaq=0;
        rep(i,1,m) if(t[i]){qaq=i;break;}
        if(!flg) {
            cout << "No" << endl;return 0;
        } else if(qaq==0||!(op[0]&&op[1])) {
            cout << "Yes" << endl;
            rep(i,1,m) {
                if(op[1]){for(int j = (i+1) % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;}
                else{for(int j = i % 2 + 1, cnt = 1; cnt <= a[i] ; j += 2, ++cnt) ans[j][i] = 1;}
            }
            rep(i,1,n) {
                rep(j,1,m) cout << ans[i][j];
                cout << endl;
            }
        }
        else{
        	for(re i=0;i<awa.size()-1;i++){
        		int l=awa[i],r=awa[i+1],ok=0;
        		if((r-l)%2==0) continue;
        		for(re j=l+1;j<r-1;j++) if(a[j]+a[j+1]<=n/2){ok=1;tag.push_back(j);}
        		if(!ok){puts("No");return 0;}
			}
			int qwq=qaq&1,nw=0,orz=0;qwq^=1;
			for(re i=1;i<=m;i++){
				qwq^=1;
				if(orz){
					int cnt=0;orz=0;
					for(re j=n-1;j>0;j-=2){
						if(cnt==a[i]) break;
						cnt++;
						ans[j][i]=1;
					}
				}
				else if(qwq){
					for(re j=1;j<=a[i]*2;j+=2) ans[j][i]=1;
				}
				else{
					for(re j=2;j<=a[i]*2;j+=2) ans[j][i]=1;
				}
				if(nw<tag.size()){if(i==tag[nw]) nw++,qwq^=1,orz=1;}
			}
			puts("Yes");
			for(re i=1;i<=n;i++,cout<<endl)
				for(re j=1;j<=m;j++) cout<<ans[i][j];
			return 0;
        }
    }
    return 0;
}
