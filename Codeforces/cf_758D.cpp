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


string s; 
ll n;
int len;
ll dp[64][64];
ll pot[64];

ll get(int r, int l){	
	if(s[l] == '0' && r > l) return LINF;
	ll u = 0;
	for(int i = l; i <= r; ++i){
		u *= 10;
		u += s[i] - '0';
	}
	return u;
}

int cant(ll x){
	int r = 0;
	while(x){
		r++;
		x /= 10;
	}
	return r;
}

ll go(int pos, int expo){
	if(pos == len){
		if(expo != -1) return -1;
		else return 0;
	}
	if(expo < 0 || len < 0) return -1;
	if(dp[pos][expo] != LINF) return dp[pos][expo];
	ll mm = LINF;
	for(int i = 0; i <= 10; ++i){
		if(pos + i + 1 > len) continue;
		
		ll ret = get(pos + i, pos);
		if(ret >= n) break;
		
		if(ret > LINF / pot[expo]) continue;
		ll u = go(pos + i + 1, expo - 1);
		if(u != -1) mm = min(mm, ret * pot[expo] + u);
	}
	if(mm == LINF) mm = -1;
	return dp[pos][expo] = mm;
}

int main(){
	fast_io();
	cin >> n >> s;
	len = int(s.size());
	for(int i = 0; i < 64; ++i){
		for(int j = 0; j < 64; ++j)
		dp[i][j] = LINF;
	}

	pot[0] = 1;
	for(int i = 1; i < 64; ++i){
		if(pot[i - 1] == LINF) pot[i] = LINF;
		else if(pot[i - 1] * n > LINF) pot[i] = LINF ;
		else pot[i] = pot[i - 1] * n;
	}
	
	ll ans = LINF;
	for(int i = 0; i <= 62; ++i){
		ll ret = go(0, i);
		if(ret != -1) ans = min(ans, ret);
	}

	cout << ans << endl;
	return 0;
} 
