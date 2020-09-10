#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
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


const long double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int mark[2 * MAXN];
int v[2 * MAXN];
vector< int > q[2 * MAXN];
ll dp[2 * MAXN]; 
int opt[2 * MAXN]; 



int extended_euclid(int a, int b, int &x, int &y) {  
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}


int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

ll go(int a, int b, int c){	
	int x, k;
	int d = extended_euclid(a, c, x, k);
	assert(b % d == 0);
	ll mul = (1LL * b) / d;
	ll rr = x * mul;
	rr %= c;
	if(rr < 0) rr += c;
	return rr;
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int x;
	for(int i = 0; i < n; ++i){
		scanf("%d", &x);
		if(x == 0) x = m;
		mark[x] = 1;
	}
	for(int i = 1; i <= m; ++i){
		if(mark[i]) continue;
		int t = gcd(i, m);
		q[t].pb(i);
		v[t]++; 
	}

	dp[m] = v[m];
	opt[m] = -1;
	for(int i = m - 1; i >= 1; --i){
		ll ret = -1;
		int ind = -1;
		for(int j = 2 * i; j <= m; j += i){
			if(dp[j] > ret){
				ret = dp[j];
				ind = j; 
			}
		}
		dp[i] = ret + v[i];
		opt[i] = ind;
	}
	int idx = -1;
	ll cur = -1;
	for(int i = 1; i <= m; ++i){
		if(dp[i] > cur){
			cur = dp[i];
			idx = i;
		}
	}	

	vector< int > ans;
	ans.pb(idx); 
	int nt = opt[idx];
	while(nt != -1){
		ans.pb(nt);
		nt = opt[nt];
	}

	vector< int > lista;
	for(auto r : ans){
		for(int i = 0; i < sz(q[r]); ++i){
			int valor = q[r][i];	
			lista.pb(valor);
		}
	}
	for(int i = 0; i < sz(lista); ++i){
		if(lista[i] == m){
			lista[i] = 0;
		}
		lista[i] %= m;
	} 
	vector< ll > to;
	to.pb(lista[0]);
	for(int i = 1; i < sz(lista); ++i){
		ll ge = go(lista[i - 1], lista[i], m);
		to.pb(ge);
	}
	printf("%d\n", sz(to));
	for(auto r : to) printf("%lld ", r);
	printf("\n"); 
	return 0;
} 
