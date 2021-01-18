#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1010;
const int mod = 998244353;

ll inv[10],a[maxn],dp[maxn];

int main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=6;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			ll tot=0,l=max(0,i-6);
			for(int j=l;j<i;j++) tot+=dp[j];
			dp[i]=tot*inv[i-l]%mod;
			if(a[i]==0) dp[i]=(dp[i]+1)%mod;
			if(a[i]==1) dp[i]=(dp[i]+2)%mod;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
