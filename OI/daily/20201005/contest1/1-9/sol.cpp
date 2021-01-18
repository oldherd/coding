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
typedef vector< vector<int> > Graph;
Graph g;

const int N = 1000;
int lst[N] , fa[N] , vis[N];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

map<pair<int,int>,bool> h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    g.resize(n + 1);
    rep(i,1,m) {
        cin >> u >> v;
        if(u > v) swap(u , v);
        if(!h[make_pair(u, v)]) {
            g[u].push_back(v);
            g[v].push_back(u);
            h[make_pair(u, v)] = true;
        }
    }
    rep(i,0,n-1) fa[i] = i;
    int k;
    cin >> k;
    memset(vis, 1, sizeof(vis));
    rep(i,1,k) cin >> lst[i] , vis[lst[i]] = 0;
    rep(i,0,n-1) {
        if(vis[i]) {
            for(int ver : g[i])
                if(vis[ver]) {
                    int x = find(i) , y = find(ver);
                    if(x != y) fa[x] = y;
                }
        }
    }
    // rep(i,0,n-1) cout << fa[i] << ' '; cout << endl;
    static int stk[N] , ans[N];
    // cout << lst[x] << endl;
    // rep(i,0,n-1) cout << vis[i] << ' '; cout << endl << endl;
    // int tot = 0;
    memset(ans , 0 , sizeof(ans));
    per(x,k,1) {
        // if(x == 3) {
        //     cout << lst[x] << endl;
        //     rep(i,0,n-1) cout << vis[i] << ' '; cout << endl << endl;
        // }
        int top = 0, cur = lst[x]; vis[cur] = 1;
        for(int ver : g[cur]) if(vis[ver]) {
            stk[++top] = ver; find(ver);
        }
        bool flg = false;
        rep(i,2,top) if(fa[stk[i]] != fa[stk[i-1]]) { flg = true; break; }
        if(flg) ans[cur] = 1;
        rep(i,2,top) {
            find(stk[i]) , find(stk[i-1]);
            if(fa[stk[i]] != fa[stk[i-1]]) fa[stk[i]] = fa[stk[i-1]];
        }
        find(cur); if(top > 0) fa[cur] = find(stk[top]);
        // rep(i,0,n-1) cout << fa[i] << ' '; cout << endl;
    }
    // rep(i,1,tot) cout << ans[i] << ' ';
    // cout << endl;
    rep(i,1,k) {
        if(ans[lst[i]]) cout << "Red Alert: ";
        cout << "City "<< lst[i] <<" is lost";
        if(ans[lst[i]]) cout << "!" << endl;
        else cout << "." << endl;
    }
    if(k == n) cout << "Game Over." << endl;
    return 0;
}