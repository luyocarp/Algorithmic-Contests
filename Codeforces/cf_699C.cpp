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

int aa[111];
int dp[111][3];
vector< int > cur[111];

int mintri(int a,int b, int c){
	return min(min(a, b), c);
}

int go(int pos, int op){
	if(pos == 0){
		if(op == 0) return 1;
		else return 0;
	}
	if(dp[pos][op] != INF) return dp[pos][op];
	
	int ret = INF;
	int gR = go(pos - 1, 0);
	int gC = go(pos - 1, 1);
	int gS = go(pos - 1, 2);
	for(int i = 0 ; i < cur[pos - 1].size() ; ++i){	
		if(cur[pos - 1][i] == op && op != 0) continue;
		if(cur[pos - 1][i] == 0){
			ret = min(ret, gR);
		}
		if(cur[pos - 1][i] == 1){
			ret = min(ret, gC);
		}
		if(cur[pos - 1][i] == 2){
			ret = min(ret, gS);
		}
	}
	if(op == 0) ++ret;
	return dp[pos][op] = ret;	
}

int main(){
	fast_io();
	int n; 
	cin >> n;
	for(int i = 0 ; i < n ; ++i) cin >> aa[i];
	for(int i = 0 ; i < n ; ++i){
		cur[i].pb(0);
		if(aa[i] == 1){
			cur[i].pb(1);
		}
		if(aa[i] == 2){
			cur[i].pb(2);
		}
		if(aa[i] == 3){
			cur[i].pb(1);
			cur[i].pb(2);
		}
	}

	for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < 3 ; ++j) 
	dp[i][j] = INF;
	
	int ans = INF;
	for(int i = 0 ; i < cur[n - 1].size() ; ++i){
		ans = min(ans, go(n-1, cur[n-1][i]));
	}
	cout << ans << endl;
	return 0;
}
