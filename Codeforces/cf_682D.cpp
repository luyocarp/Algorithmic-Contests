#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
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
//const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7; 
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;

int n;
int m;
int k;
string s;
string t;
int dp[1001][1001][11][2];

int go(int nn, int mm, int k, int p){
	if(k < 0 || nn < 0 || mm < 0) return -INF;
	if(k == 0) return 0;
	if(dp[nn][mm][k][p] != - 1) return dp[nn][mm][k][p];
	if(!p){
		if(nn == 0 || mm == 0){
			if(k >= 2) return dp[nn][mm][k][p] = -INF;
			else if(k == 1){
				if(s[nn] == t[mm]) return dp[nn][mm][k][p] = 1;
				else{
					if(nn == 0 && mm == 0){
						if(s[nn] == t[mm]) return dp[nn][mm][k][p] = 1;
						else return dp[nn][mm][k][p] = -INF;
					}
					else if(nn == 0) return dp[nn][mm][k][p] = go(nn, mm - 1, k, p);
					else if(mm == 0) return dp[nn][mm][k][p] = go(nn - 1, mm, k, p);
				}
			}
			else if(k == 0) return dp[nn][mm][k][p] = 0;
		}
	}
	else{
		if(nn == 0 || mm == 0){
			if(s[nn] != t[mm]) return dp[nn][mm][k][p] = -INF;
			else return dp[nn][mm][k][p] = 1;
		}
	}
	
	int ret1, ret2, ret3, ret4;
	if(!p){
	    ret1 = go(nn - 1, mm, k, 0);
	    ret2 = go(nn, mm - 1, k, 0);
	    if(s[nn] == t[mm]) ret3 = go(nn - 1, mm - 1, k - 1, 0) + 1;
	    else ret3 = -INF;
            if(s[nn] == t[mm]) ret4 = go(nn - 1, mm - 1, k, 1) + 1;
	    else ret4 = -INF;
	    return dp[nn][mm][k][p] = max(max(ret1, ret2), max(ret3, ret4));
	}
	else{
	    if(s[nn] != t[mm]) return dp[nn][mm][k][p] = -INF;
	    else{
		ret1 = go(nn - 1, mm - 1, k - 1, 0) + 1;
		ret2 = go(nn - 1, mm - 1, k, 1) + 1;
		return dp[nn][mm][k][p] = max(ret1, ret2);
	    }
	}
}

int main(){
	fast_io();
	cin >> n >> m >> k;
	cin >> s;
	cin >> t;
	for(int i = 0 ; i < 1001 ; ++i)
	for(int j = 0 ; j < 1001 ; ++j)
	for(int r = 0 ; r < 11 ; ++r)
	for(int u = 0 ; u < 2 ; ++u)
	dp[i][j][r][u] = -1;
	cout << go(n - 1, m - 1, k, 0) << endl;
	return 0;
}
