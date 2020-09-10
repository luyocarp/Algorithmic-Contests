#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define REP(i,x,y) for(int (i) = (x) ; (i) < (y) ; ++(i))
#define REPIT(it,A) for(__typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
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
//const double E = 2.718281828459;
const uint  INF = 2e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 2;



uint grid[4004][4004];
uint cum[4004][4004];
uint dp[808][4004];
char st[8008];

inline uint get_info(uint i, uint j){
	return cum[j][j] + cum[i-1][i-1] - cum[i-1][j] - cum[j][i-1];
}

void compute(uint kk, uint L, uint R, uint optL, uint optR){
	if(L > R) return;
	uint mid = (L + R) >> 1;
	uint optimo = INF;
	dp[kk][mid] = INF;
	for(int i = optL; i <= min(optR, mid - 1); ++i){
		uint cur = dp[kk-1][i] + get_info(i + 1, mid);
		if(dp[kk][mid] > cur){
			dp[kk][mid] = cur;
			optimo = i;
		}
	}	
	compute(kk, L, mid - 1, optL, optimo);
	compute(kk, mid + 1, R, optimo, optR);
}

int main(){
	uint n,k; scanf("%u %u\n", &n, &k);
	for(uint i = 1; i <= n; ++i){
		gets(st);
		for(uint j = 1; j <= n; ++j){
			grid[i][j] = st[2*j - 2] - '0';
		}
	}
	
	for(uint i = 1; i <= n; ++i){
		cum[i][1] = cum[i-1][1] + grid[i][1];
		cum[1][i] = cum[1][i-1] + grid[1][i];
	}

	for(uint i = 2; i <= n; ++i){
		for(uint j = 2; j <= n; ++j){
			cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + grid[i][j];
		}
	}

	dp[0][0] = 0;	
	for(uint i = 1; i <= n; ++i) dp[0][i] = INF;
	
	for(uint kk = 1; kk <= k; ++kk){
		compute(kk, 1, n, 0, n);
	}

	printf("%u\n", dp[k][n]/2);
	return 0;
} 
