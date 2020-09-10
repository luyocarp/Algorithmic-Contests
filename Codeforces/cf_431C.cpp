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

int n, k, d;
ll dp[2][102][102];

ll go(int al, int len, int val){
	if(dp[al][len][val] != -1) return dp[al][len][val];
	if(len == 1){
		if(val < 1 || val > k) return 0;
		if(al == 1){
			if(val >= d) return 1;
			else return 0;
		}
		else{
			return 1;
		}
	}
	ll ans = 0;
	if(al == 1){
		for(int i = 1; i < d; ++i){
			if(val >= i) ans = (ans + go(1, len - 1, val - i)) % MOD;
		}
		for(int i = d; i <= min(val, k); ++i){
			if(val >= i) ans = (ans + go(0, len - 1, val - i)) % MOD;
		}
	}
	else{
		ans = 0;
		for(int i = 1; i <= min(val, k); ++i){
			if(val >= i) ans = (ans + go(0, len - 1, val - i)) % MOD;
		}
	}
	
	return dp[al][len][val] = ans;	
}

int main(){
	cin >> n >> k >> d;
	ll ans = 0;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 102; ++j){
			for(int r = 0; r < 102; ++r){
				dp[i][j][r] = -1;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		ans = (ans + go(1, i, n)) % MOD;
	}
	cout << ans << endl;
	return 0;
} 
