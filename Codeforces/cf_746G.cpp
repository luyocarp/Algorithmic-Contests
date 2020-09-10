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
const ll LINF = 1e16 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


vector< int > v[2 * MAXN];
vector< int > ad[2 * MAXN];
int a[2 * MAXN];
int b[2 * MAXN];

void nada(){
	cout << -1 << endl;
}


int main(){
	fast_io();
	int n, t, k; cin >> n >> t >> k;
	for(int i = 1; i <= t; ++i){
		cin >> a[i];
	}

	int ret = 0;
	for(int i = 1; i <= t - 1; ++i){
		if(a[i] > a[i + 1]){
			ret += a[i] - a[i + 1];	
			b[i] = a[i + 1];
		}
		else b[i] = a[i];
	}

	ret += a[t];
	if(ret > k){
		nada();
		return 0;
	}
	int u = 2;
	for(int i = 1; i <= t; ++i){
		for(int j = 0; j < a[i]; ++j){
			v[i].pb(u);
			u++;
		}
	}
	
	int falta = k - ret;
	bool ok = 0;
	for(int i = 0; i < a[1]; ++i){
		int w = v[1][i];
		ad[1].pb(w);
	}
	for(int i = 1; i <= t - 1; ++i){
		if(!ok){
			if(b[i] - 1 >= falta){
				for(int j = 0; j < b[i] - falta; ++j){
					int s = v[i][j];
					int w = v[i + 1][j];
					ad[s].pb(w);
				}
				for(int j = b[i] - falta; j < a[i + 1]; ++j){
					int s = v[i][0];
					int w = v[i + 1][j];
					ad[s].pb(w);
				}
				ok = 1;
				falta = 0;
			}
			else{
				falta -= (b[i] - 1);
				for(int j = 0; j < a[i + 1]; ++j){
					int s = v[i][0];
					int w = v[i + 1][j];
					ad[s].pb(w);
				}
			}

		}
		else{
			for(int j = 0; j < b[i]; ++j){
				int s = v[i][j];
				int w = v[i + 1][j];
				ad[s].pb(w);
			}
			for(int j = b[i]; j < a[i + 1]; ++j){
				int s = v[i][0];
				int w = v[i + 1][j];
				ad[s].pb(w);
			}

		}
	}
		
	if(falta > 0) nada();
	else{		
		cout << n << endl;
		for(int i = 0; i < 2 * MAXN; ++i){
			if(ad[i].empty()) continue;
			for(int j = 0; j < int(ad[i].size()); ++j){
				cout << i << " " << ad[i][j] << endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}
