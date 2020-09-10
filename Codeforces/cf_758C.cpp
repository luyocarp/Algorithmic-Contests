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

ll t[102][102];


int main(){
	fast_io();
	ll n, m;
	ll k, x, y;
	cin >> n >> m >> k >> x >> y;
	--x, --y;
	if(n == 1){
		ll ret = k / m;
		ll us = k % m;
		for(int i = 0; i < m; ++i) t[0][i] = ret;
		for(int i = 0; i < us; ++i) t[0][i] ++;
		ll menor = LINF, mayor = 0;
		for(int i = 0; i < m; ++i){
			menor = min(menor, t[0][i]);
			mayor = max(mayor, t[0][i]);
		}
		cout << mayor << " " << menor << " " << t[x][y] << endl;
		return 0;
	}

	ll ret = k / (2 * (n - 1) * m);
	for(int i = 1; i < n - 1; ++i){
		for(int j = 0; j < m; ++j) 
		t[i][j] = 2 * ret;
	}
	for(int j = 0; j < m; ++j){
		t[0][j] = t[n - 1][j] = ret;
	}
	k %= (2 * (n - 1) * m);

	int cur = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(cur < k){
				t[i][j]++;
				++cur;
			}
		}
	}

	for(int i = n - 2;  i >= 0; --i){
		for(int j = 0; j < m; ++j){
			if(cur < k){
				t[i][j]++;
				++cur;
			}
		}
	}	
	
	ll menor = LINF, mayor = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m ; ++j){
			menor = min(menor, t[i][j]);
			mayor = max(mayor, t[i][j]);
		}
	}

	cout << mayor << " " << menor << " " << t[x][y] << endl;
	return 0;
} 
