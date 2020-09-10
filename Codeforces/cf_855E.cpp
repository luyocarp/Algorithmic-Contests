#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << ": " << x << endl;
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(auto it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) int(v.size())
 
 
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;
typedef vector<int> vi;
typedef unsigned int ui;
typedef vector<ii> vii;
 

const long double PI = acos(-1);
const int  INF = 2e9 + 5;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;


int base[64];
ll C[84][84];
ll dp[1 << 11][64][12];


ll go(int mask, int n, int pos) {
	if(dp[mask][n][pos] != -1) return dp[mask][n][pos];
	if(pos == 0) {
		if(n < 0) return 0;
		int r = mask & 1;
		if(n % 2 != r) return 0;
		return 1;
	}
	ll ans = 0;
	int r = (mask >> pos) & 1;
	int newmask = mask;
	if(r == 1) newmask = mask ^ (1 << pos);
	for(int i = r; i <= n; i += 2) {
		ans += go(newmask, n - i, pos - 1) * C[n][i];
	}
	return dp[mask][n][pos] = ans;
}

ll Get(int mask, int n, int b) {
	return go(mask, n, b - 1);
}	

ll Query(int b, ll r) {
	if(r == 0) return 0;
	int cnt = 0;
	ll rr = r;
	while(rr) {
		base[cnt] = rr % b;
		rr /= b;
		++cnt;
	}

	ll ans = 0;
	int mask = 0;
	int newmask;
	for(int j = 1; j < base[cnt - 1]; ++j) {
		newmask = mask;
		newmask ^= (1 << j);
		ans += Get(newmask, cnt - 1, b);		
	}

	mask ^= (1 << base[cnt - 1]);
	
	for(int i = cnt - 2; i >= 0; --i) {
		for(int j = 0; j < base[i]; ++j) {
			newmask = mask ^ (1 << j);
			ans += Get(newmask, i, b);
		}
		mask ^= (1 << base[i]);
	}
	ans += Get(mask, 0, b);
	for(int i = 0; i <= cnt - 2; ++i) {
		for(int j = 1; j < b; ++j) {
			ans += Get(1 << j, i, b);
		}
	}		
	return ans;
}


int main() {
	for(int i = 0; i < 84; ++i) C[i][0] = 1, C[0][i] = 0;
	C[0][0] = 1;
	
	for(int i = 1; i < 84; ++i) {
		for(int j = 1; j < 84; ++j) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}

	for(int i = 0; i < 1 << 11; ++i) {
		for(int j = 0; j < 64; ++j) {
			for(int k = 0; k < 12; ++k) 
				dp[i][j][k] = -1;
		}
	}

	int q; scanf("%d", &q);
	int b; 
	ll l, r;
	for(int query = 1; query <= q; ++query) {
		scanf("%d %lld %lld", &b, &l, &r);
		printf("%lld\n", Query(b, r) - Query(b, l - 1));
	}
	return 0;
} 
