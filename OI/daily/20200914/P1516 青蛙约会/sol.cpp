#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void exgcd(ll a , ll b , ll &x , ll &y , ll &g) {
	if(!b) {
		g = abs(a); x = a > 0 ? 1 : -1; y = 0;
		return;
	}
	exgcd(b , a%b , y , x , g);
	y -= a / b * x;
}

int main() {
	ll x , y , m , n , l , k , g , t;
	cin >> x >> y >> m >> n >> l;
	exgcd(n - m , l , t , k , g);
	if((x - y) % g) cout << "Impossible" << endl;
	else {
		t *= (x - y) / g;
		ll md = l / g;
		cout << (t % md + md) % md << endl;
	}
	return 0;
}
