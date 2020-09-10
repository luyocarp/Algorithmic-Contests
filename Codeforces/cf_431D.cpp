#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
//#define ones(x) __builtin_popcount(x)
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


int a[64];
ll dp[2][64][65];

ll go(int have, int pos, int ones){
	if(pos == 0){
		if(have){
			if(a[0] == 0){
				if(ones == 0) return 1;
				else return 0;
			}
			else{
				if(ones == 0 || ones == 1) return 1;
				else return 0;
			}
		}
		else{
			if(ones == 0 || ones == 1) return 1;
			else return 0;	
		}
	}
	if(ones < 0) return 0;
	if(dp[have][pos][ones] != -1) return dp[have][pos][ones];
	ll ret = 0;
	if(have){
		ret = 0;
		if(a[pos] == 0){
			ret = go(have, pos - 1, ones);
		}
		else{
			ret = go(have, pos - 1, ones - 1);
			ret += go(0, pos - 1, ones);
		}
	}	
	else{
		ret = 0;
		ret = go(0, pos - 1, ones);
		ret += go(0, pos - 1, ones - 1);
	}
	
	return dp[have][pos][ones] = ret;
}

ll get(ll n, ll k){
	for(int i = 0; i <= 63; ++i){
		if(n & (1LL << i)) a[i] = 1;
		else a[i] = 0;
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 64; ++j){
			for(int r = 0; r < 65; ++r){
				dp[i][j][r] = -1;
			}
		}
	}
	return go(1, 63, k);
}

ll cant(ll mid, ll k){
	return get(2 * mid, k) - get(mid, k);
}

int main(){
	ll m, k; cin >> m >> k;
	ll lo = 1, hi = 1e18 + 5;
	while(lo < hi){
		ll mid = (lo + hi) / 2;
		if(cant(mid, k) >= m) hi = mid;
		else lo = mid + 1;
	}
	cout << lo << endl;
	return 0;
} 
