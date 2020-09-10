#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> ill;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef pair<int,bool> ib;
typedef unsigned int uint;


const double PI = acos(-1);
const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7; 
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;

set< int > tt;
set< int > :: iterator it;
map< int, vector< int > > entra;
map< int, vector< int > > sale;
set< int > sw;
ll fact[2 * MAXN + 10];
ll invfact[2 * MAXN + 10];

ll binpow(ll a, ll n){
	if(n == 0) return 1;
	ll ans;
	if(n & 1) return a * binpow(a, n - 1) % MOD;
	ans = binpow(a, n/2);
	return ans*ans%MOD;
}

ll comb(ll n, ll k){
	if(n < k) return 0LL;
	ll ans = (fact[n] * invfact[k]) % MOD;
	ans = (ans * invfact[n - k]) % MOD;
	return ans;
}

int main(){
	int n,k ; scanf("%d %d", &n, &k);
	fact[0] = 1;
	invfact[0] = 1;
	for(int i = 1 ; i < 2 * MAXN + 5 ; ++i) fact[i] = (fact[i - 1]*i) %MOD;
	for(int i = 1 ; i < 2 * MAXN + 5 ; ++i) invfact[i] = binpow(fact[i], MOD - 2);

	int x, y;
	for(int i = 0 ; i < n ; ++i){
		scanf("%d %d", &x, &y);
		tt.insert(x); tt.insert(y);
		entra[x].pb(i);
		sale[y].pb(i);
	}

	ll ans = 0;
	ll last = 0;
	for(it = tt.begin() ; it != tt.end() ; ++it){
		int cur = sw.size();
		int ret = *it;
		int len = entra[ret].size(); 
		ans = (ans + (comb(cur, k) * (ret - last - 1) % MOD)) % MOD;
		for(int i = 0 ; i < len ; ++i){
			sw.insert(entra[ret][i]);
		}
		ans = (ans + comb(cur + len, k)) % MOD;	
		last = ret;
		for(int i = 0 ; i < sale[ret].size() ; ++i){
			sw.erase(sale[ret][i]);
		}
	}

	ans = ans % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << endl;

	return 0;
}
