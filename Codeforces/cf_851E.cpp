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

const int MAX = 1e5 + 1;

bool prime[MAX];
ll primos[MAX];
int cp = 0;

int a[128];

int sol[32 * 100];

map< int, int > mapa;
int gid = 0;

int Get(int u) {
	if(mapa.count(u)) return mapa[u];
	mapa[u] = gid;
	gid ++;
	return gid - 1;
}

map< int, int > dp;

int solve(int u) {
	if(u <= 1) return dp[u] = 0;
	if(dp.count(u)) return dp[u];
	// mask of u
	int idx = -1;
	for(int i = 30; i >= 0; --i) {
		if((1 << i) <= u) {
			idx = i;
			break;
		}
	}

	int v = u;
	int w = 0;
	int t = 0;
	int sh = idx;
	set< int > save;
	while(idx != 0) {
		v -= u & (1 << idx);
		t += u & (1 << idx);
		w = v | (t >> sh);
		save.insert(solve(w));
		--idx;
		--sh;
	}

	for(int i = 0; ; ++i) {
		if(!save.count(i)) return dp[u] = i;
	}
	
}

int y[32];

int main() {
	fast_io();
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];	
	}

 	prime[0] = prime[1] = 1;
	for(int i = 2; i * i < MAX; ++i) {
		if(!prime[i])
		for(int j = i * i; j < MAX; j += i) {
			prime[j] = 1;
		}
	}

	for(int i = 0; i < MAX; ++i) {
		if(!prime[i]) {
			primos[cp ++] = i;
		}
	}
	
	for(int i = 0; i < n; ++i) {
		int u = a[i];
		for(int j = 0; j < cp; ++j) {
			if(primos[j] * primos[j] > u) break;
			if(u % primos[j] == 0) {
				int ex = 0;
				while(u % primos[j] == 0) {
					ex ++;
					u /= primos[j];
				}
				sol[Get(primos[j])] |= (1 << ex);
			}
		}
		if(u != 1) {
			sol[Get(u)] |= (1 << 1);
		}
	}

	ll ans = 0;
	for(int i = 0; i < 32 * 100; ++i) {
		if(sol[i] != 0) {
			ans ^= solve(sol[i]);
		}
	}

	if(ans == 0) {
		cout << "Arpa" << endl;
	}
	else cout << "Mojtaba" << endl;
	return 0;
} 
