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
#define itm3 snd
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


ll x[MAXN]; 
ll tmp[50]; 
ll n; 


ll get(ll a, ll w){
	if(a % w == 0) return a / w;
	else return a / w + 1;
}

vector< pair< ll, ll > > v;

int go(int pos, ll a, ll b){
	for(int i = pos; i < n; ++i){
		tmp[i - pos] = x[i];
	}

	int len = n - pos;
	int mid = (len + 1) / 2;
	v.clear(); 
	for(int i = 0; i < 1 << (mid); ++i){
		ll ret = 1; 
		for(int j = 0; j < mid; ++j){
			if(i & (1LL << j)){ 
				if(ret < 1e6){
					ret *= tmp[j];
				}
			}
		}
		v.pb(mp(ret, i)); 
	}
	
	for(int i = 0; i < sz(v); ++i){
		ll mask = v[i].snd;
		ll prod = v[i].fst;
		for(int j = mid; j < len; ++j){
			if(prod >= a){
				break;
			}
			else{
				prod *= tmp[j];
				mask |= (1LL << j);
			}
			
		}
		if(prod < a) continue;
		ll tmask = ((1LL << len) - 1) ^ mask;
		ll tr = 1;
		for(int r = 0; r < len; ++r){
			if(tmask & (1LL << r)){
				if(tr >= b){
					return len;
				}
				else{
					tr *= tmp[r];
				}
			}
		}
		if(tr >= b) return len; 
	}
	
	return INF;	
}

int main(){
	ll a, b, h, w; 
	scanf("%lld %lld %lld %lld %lld", &a, &b, &h, &w, &n);
	for(int i = 0; i < n; ++i){
		scanf("%lld", &x[i]);	
	}
	
	sort(x, x + n);
	int ans = INF;
	if(w >= a && h >= b){
		ans = 0;
	}
	if(w >= b && h >= a){
		ans = 0;
	}
	if(ans == 0){
		printf("0\n");
		return 0;
	}
	for(int i = n - 1; i >= max(0LL, n - 34); --i){
		int g1 = go(i, get(a, h), get(b, w));
		int g2 = go(i, get(a, w), get(b, h));
		int g3 = go(i, get(b, w), get(a, h));
		int g4 = go(i, get(b, h), get(a, w));
		if(g1 != INF){
			ans = min(ans, g1); 
		}
		if(g2 != INF){
			ans = min(ans, g2);	
		}
		if(g3 != INF){
			ans = min(ans, g3);
		}
		if(g4 != INF){
			ans = min(ans, g4); 
		}
		if(ans != INF){
			break;
		}
	}
	
	if(ans == INF){
		printf("-1\n");	
	}
	else{
		printf("%d\n", ans); 
	}
	return 0;
} 
