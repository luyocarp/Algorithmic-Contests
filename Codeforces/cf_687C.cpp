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


int mark[505][505];
int tt[505];
set < int > ans;
set<int> ::iterator it;
int dp[505];

int main(){
	int n, k; scanf("%d %d",&n,&k);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d",&tt[i]);
	}
	sort(tt, tt + n);
	
	for(int i = 0; i < 505 ; ++i)
	for(int j = 0 ; j < 505 ; ++j)
	mark[i][j] = INF;

	for(int i = 0 ; i < 505 ; ++i)
	dp[i] = INF;
	
	mark[0][0] = -1;
	dp[0] = -1;
	dp[tt[0]] = 0;
	for(int x = 0 ; x < 505 ; ++x){
		for(int i = 1 ; i < n ; ++i){
			if(tt[i] > x) break;
			if(dp[x - tt[i]] < i){
				dp[x] = min(dp[x], i);
			}
		}	
	}	

	for(int x = 0; x < 505 ; ++x){
		if(dp[x] != INF) mark[0][x] = dp[x];
	}

	for(int val = 1 ; val < 505 ; ++val){
		for(int x = 0; x <= val ; ++x){
			for(int i = 0 ; i < n ; ++i){
				if(tt[i] > val) continue;
				if(mark[x][val - tt[i]] < i){
					mark[x][val] = min(mark[x][val], i);
				}
				if(x >= tt[i] && mark[x - tt[i]][val - tt[i]] < i){
					mark[x][val] = min(mark[x][val], i);
				}
			}
		}
	}

	for(int i = 1 ; i < 505 ; ++i){
			if(mark[i][k] != INF){
				ans.insert(i);
			}
	}
	ans.insert(0);
	printf("%d\n", ans.size());
	for(it = ans.begin() ; it != ans.end()  ;++it){
		printf("%d ", *it);
	}
	return 0;
} 
