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
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;

ll a[MAXN];
ll b[MAXN];
int m, n;

bool ok(ll r){
	
	int l = 0, s = 0;
	int cover = 0;
	while(l < m && s < n){
		if(a[s] > b[l] + r){
			++l;
		}
		else if(a[s] < b[l] - r){
			return 0;
		}
		else{
			++s;
			++cover;
		}
	}
	if(cover == n) return 1;
	else return 0;
}

int main(){
	fast_io();
	cin >> n >> m;
	for(int i = 0 ; i < n ; ++i) cin >> a[i];
	for(int i = 0 ; i < m ; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);

	ll lo = 0, hi = 1e10;
	
	while(lo < hi){
		ll mid = (lo + hi)/2;
		if(ok(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
	return 0;
}
