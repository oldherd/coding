#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn = 234567;

ll f[maxn] ,g[maxn], tmp[maxn];
int in[maxn], out[maxn];
int vis[maxn], t[maxn], a[maxn];
int h[maxn << 1],to[maxn << 1],ver[maxn << 1], cnt = 0; 

inline bool cmp(int x,int y) {return x>y;}
inline void add(int x,int y) {
	to[++cnt] = y;
	ver[++cnt]= h[x];
	h[x]=cnt;
}

inline void dfs(int x,int fa=0) {
    vis[x]=1;
    int num=0; ll cur=0;
    for(register int i=h[x];i;i=ver[i]) {
        int y=to[i];
        if(y==fa) continue;
        dfs(y,x);
    }
    for(register int i=h[x];i;i=ver[i]) {
        int y=to[i];
        if(y==fa) continue;
        tmp[++num]=g[y]-f[y];
        cur+=f[y];
    }
    std::sort(tmp+1,tmp+1+num,cmp);
    for(register int i=0;i<=num;++i) {
        cur+=tmp[i];
        if(fa) {
            f[x]=max(f[x],min(out[x]+i+1,in[x]+num-i)*(ll)t[x]+cur);
            g[x]=max(g[x],min(out[x]+i,in[x]+num-i+1)*(ll)t[x]+cur);
        }
        else f[x]=max(f[x],min(out[x]+i,in[x]+num-i)*(ll)t[x]+cur);
    }
}
int main() {
	int n; cin >> n;
    ll ans = 0;
    for(register int i=1;i<=n;++i) cin >> t[i];
    for(register int i=1;i<=n;++i) ;
    for(register int i=1;i<n;++i) {
        int x=read(),y=read();
        ans+=t[x]+t[y];
        if(a[x]==a[y]) {add(x,y);add(y,x);}
        else {if(a[x]>a[y]) swap(x,y); ++in[x];++out[y];}
    }
    for(register int i=1;i<=n;++i) {
        if(!vis[i]) {dfs(i);ans-=f[i];}
    }
    printf("%lld\n",ans);
    return 0;
}
