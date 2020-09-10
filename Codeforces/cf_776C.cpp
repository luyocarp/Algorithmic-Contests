#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << ": " << x << endl;
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(auto it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) int(v.size())

//#define DEBUG 1

#define EPS 1e-7

typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 5;


ll a[MAXN]; 
ll pot[100];
ll pref[MAXN]; 
int cnt = 0;
map< ll, vector< int > > mapa;

int main(){
	ll n, k; scanf("%I64d %I64d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%I64d", a + i); 
	}
	set< ll > pt;
	pt.clear(); 
	if(abs(k) != 1){
		pot[0] = 1;
		cnt = 1;
		for(int i = 1; ; ++i){
			if(abs(pot[cnt - 1] * k) > 1e15) break;
			pot[cnt] = pot[cnt - 1] * k;
			++cnt; 
		}	
	
		for(int i = 0; i < cnt; ++i) pt.insert(pot[i]);
		cnt = 0;
		for(auto it = pt.begin(); it != pt.end(); ++it){
			pot[cnt] = *it;
			++cnt; 
		}
	}
	else{
		if(k == 1){
			pot[0] = 1;
			cnt = 1;
			pt.insert(1); 
		}
		else{
			pot[0] = -1;
			pot[1] = 1;
			cnt = 2;
			pt.insert(1);
			pt.insert(-1); 
		}
	}
	
	pref[0] = a[0];
	for(int i = 1; i < n; ++i) pref[i] = pref[i -  1] + a[i];
	for(int i = 0; i < n; ++i){
		mapa[pref[i]].pb(i); 
	}

	ll ans = 0;
	for(int i = 0; i < n; ++i){
		if(pt.count(pref[i])) ++ans; 
	}
	ll ret;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < cnt; ++j){
			ret = pref[i] + pot[j]; 
			if(mapa.count(ret)){
				int pos = lower_bound(all(mapa[ret]), i + 1) - mapa[ret].begin();
				int len = int(mapa[ret].size());
				if(pos >= 0 && pos <= (len - 1)) ans += (len - pos); 
			}
		}
	}

	printf("%I64d\n", ans); 
	return 0;
} 
