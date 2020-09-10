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

ll aa[2 * MAXN];
string s;
int n;

bool ok(ll mid){
	for(int i = 0; i < n ; ++i){
		if(s[i] == 'R') aa[i] += mid;
		else aa[i] -= mid;
	}
	bool ret = 0;
	for(int i = 1 ; i < n  ; ++i){
		if(aa[i] <= aa[i - 1]){
			ret = 1;
			break;
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		if(s[i] == 'R') aa[i] -= mid;
		else aa[i] += mid;
	}
	return ret;
}

int main(){
	fast_io();
	cin >> n;
	cin >> s;
	for(int i = 0 ; i < n ; ++i)  cin >> aa[i];
	ll lo = 0, hi = 1e10;
	if(!ok(hi)){
		cout << "-1" << endl;
		return 0;
	}

	while(lo < hi){
		ll mid = (lo + hi)/2;
		if(ok(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
	return 0;
}
