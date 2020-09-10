#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(__typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
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
typedef pair<ill, ll> tri;
typedef pair<int,bool> ib;
typedef unsigned int uint;


const double PI = acos(-1);
const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


ll C2(ll x) {
	ll ret = (x-1)*x;
	return ret/2;
}


ll get(ll x, ll y) {
	if (x % y == 0) return x/y;
	else return x/y + 1;	
}


ll binpow(ll a, ll r) {
	if (r == 0) return 1;
	if (r%2 == 1) return a*binpow(a,r-1);
	ll tmp = binpow(a,r/2);
	return tmp*tmp;
}

ll is(ll x, ll n, ll r) {
	if (x == 1) return r;
	ll ans = 1;
	for (int i = 0; i < n - 1; ++i) {
		ans *= x;
		if (ans > r) return 0;
	}
	return r/ans;	
}

ll pot[3200];
int gcd[3200][3200];

int main() {
	fast_io();
	ll n, l , r; cin >> n >> l >> r;
	if (n == 1) {
		cout << r - l + 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 2 * C2(r - l + 1) << endl;
		return 0;
	}

	for (int i = 1; i < 3200; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i % j == 0) gcd[i][j] = j;
			else {
				int ret = i % j;
				gcd[i][j] = gcd[j][ret];
			}
		}
	}

	for (int i = 0; i < 3200; ++i) pot[i] = binpow(i, n - 1);
	ll ans = 0;
	for (int x = 1; x < 3200; ++x) {
		ll ret = is(x, n , r);
		if (ret != 0) {
			for (int y = 1; y < x; ++y) {
				if (gcd[x][y] != 1) continue;
				ll lo = get(l, pot[y]);
				if (ret >= lo) ans += (ret - lo + 1);
			}
		}
	}

	cout << 2 * ans << endl;
	return 0;
}
