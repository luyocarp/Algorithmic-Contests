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
#define itm3 snd.fst
#define itm4 snd.snd
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

const int BLOCK = 320;


int dp[MAXN][BLOCK]; 
int a[MAXN]; 

int go(int p, int k, int n){
	if(p >= n) return 0; 
	if(dp[p][k] != -1) return dp[p][k]; 
	return dp[p][k] = go(p + a[p] + k, k, n) + 1;
}

int solve(int p, int k, int n){
	if(k >= BLOCK){
		int steps = 0;
		while(p < n){
			int nt = p + a[p] + k;
			steps ++;
			p = nt; 
		}
		return steps;
	}
	else return go(p, k, n); 
}

int main(){
	fast_io();
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < BLOCK; ++j) 
			dp[i][j] = -1;

	int n; cin >> n;	
	for(int i = 0; i < n; ++i) cin >> a[i];
	int queries; cin >> queries;
	int p, k; 
	for(int q = 0; q < queries; ++q){
		cin >> p >> k;
		--p; 
		cout << solve(p, k, n) << endl; 
	}
	return 0;
} 
