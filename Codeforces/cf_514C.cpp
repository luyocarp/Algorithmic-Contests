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


const double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e6 + 3;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;

const ll HASH = 1000000000000000009;
const ll pol = 1009;
ll pot[6 * MAXN];

set< pair< int , ll > >sw;

ll mul(ll a, ll b, ll m){
	ld ret = ld(a) * ld(b) / ld(m);
	ll q = ll(ret); 
	ll r = a * b - m * q;
	while(r < 0) r += m;
	while(r >= m) r -= m;
	return r;
}

ll get_hash(string s){
	int len = sz(s);
	ll ans = 0;
	for(int i = 0; i < len; ++i){
		ans += mul(pot[i], s[i], HASH);
		ans %= HASH;
	}
	return ans;
}

void generate(string s){
	int len = sz(s);
	ll value = get_hash(s);	
	ll ret = 0;
	for(int i = 0; i < len; ++i){
		for(char j = 'a'; j <= 'c'; ++j){
			if(j == s[i]) continue;
			ret = value - mul(pot[i], s[i], HASH);
			ret %= HASH;
			ret += mul(pot[i], j, HASH);
			ret %= HASH;
			if(ret < 0) ret += HASH;
			sw.insert(mp(len, ret));
		}
	}
}

int main(){
	pot[0] = 1;
	for(int i = 1; i < 6 * MAXN; ++i) pot[i] = mul(pot[i - 1], pol, HASH);
	fast_io();
	int n, m; cin >> n >> m;
	string s;
	for(int i = 0; i < n; ++i){
		cin >> s;
		generate(s);
	}

	#ifdef DEBUG
	for(auto it = sw.begin(); it != sw.end(); ++it){
		cout << it -> fst << " " << it -> snd << endl;
	} 
	#endif

	for(int i = 0; i < m; ++i){
		cin >> s;
		int len = sz(s); 
		ll vh = get_hash(s);
		if(sw.count(mp(len, vh))) cout << "YES" << endl;
		else cout << "NO" << endl; 
	}
	return 0;
} 
