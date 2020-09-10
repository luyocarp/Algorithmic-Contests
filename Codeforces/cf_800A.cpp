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


#define EPS 1e-12

ll a[ MAXN];
ll b[ MAXN]; 
ll n, p;
ld l[ MAXN];
ld cero = 0.0;


int ok(ld t){
	for(int i = 0; i < n;++i){
		ld  x = a[i] * t - b[i];
		x /= p;
		l[i] = max(cero, x);		
	}

	ld cur = 0;
	for(int i = 0; i < n; ++i) cur += l[i];
	if(abs(cur - t) > EPS && cur > t) return 0;
	else return 1; 
}

int main(){
	scanf("%lld %lld", &n, &p);
	for(int i = 0; i < n; ++i){
		scanf("%lld %lld", &a[i], &b[i]);
	}
	ll cur = 0;
	for(int i = 0; i < n; ++i) cur += a[i];
	if(cur <= p){
		cout << -1 << endl;
		return 0;
	}
	ld lo = 0.0, hi = 1e20;
	for(int it = 0; it < 300; ++it){
		ld t = (lo + hi) / 2;
		if(ok(t)){
			lo = t;
		}
		else hi = t;
	}
	
	cout << fixed << setprecision(10) << lo << endl; 
	return 0;
}
