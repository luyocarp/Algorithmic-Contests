#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
//#define ones(x) __builtin_popcount(x)
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

#define EPS 1e-9

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
const int MN = 1e6 + 2;

ll get(ll n){
	if(n == 0) return 0;
	return 2 * get(n / 2) + 1;
}

ll ones(ll n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n % 2 == 1) return 2 * ones(n / 2) + 1;
	else return 2 * ones(n / 2); 
}

ll go(ll n, ll l, ll r){
	if(n == 1) return 1;
	ll ret = get(n / 2);
	ll ret1 = 2 * ret + 1;
	if(l == 0 && r == (ret1 - 1)){
		return ones(n);
	}
	if(r < ret){
		return go(n / 2, l, r);
	}
	else{
		if(r == ret){
			if(l == ret) return (n % 2); 
			return go(n / 2, l, r - 1) + (n % 2);
		}
		else{
			if(l == ret) return (n % 2) + go(n / 2, 0, r - ret - 1);
			if(l > ret) return go(n / 2, l - ret - 1, r - ret - 1); 
			return go(n / 2, l, ret - 1) + go(n / 2, 0, r - ret - 1) + n % 2;
		}
	}

}

int main(){
	fast_io();
	ll n, l, r; cin >> n >> l >> r;
	--l, --r;
	if(n == 0) cout << 0 << endl; 
	else 	cout << go(n, l, r) << endl;
	return 0;
} 
