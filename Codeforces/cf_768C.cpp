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

vector< int > a;
map< vector< int >, int > mapa;
vector< int > r[MAXN];

int main(){
	int n, k, x; scanf("%d %d %d", &n, &k, &x);
	int t;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &t); 
		a.pb(t); 
	}
	sort(all(a));
	r[cnt++] = a;
	mapa[a] = 0;
	int tt = -1;
	int idx = -1;
	for(int _ = 1; _ <= k; ++_){
		for(int i = 0; i < n; ++i){
			if(i % 2 == 0) a[i] ^= x;
		}
		sort(all(a));
		if(mapa.count(a)){
			idx = mapa[a];
			tt = _ - idx;
			break; 
		}
		else{
			mapa[a] = _;
			r[cnt++] = a;
		}
	}

	if(tt == -1 && idx == -1) {
		sort(all(a));
		cout << a[n - 1] << " " << a[0] << endl; 
	}
	else{
		int ts = (k - idx) % tt;
		ts += idx;
		cout << r[ts][n - 1] << " " << r[ts][0] << endl; 
	}	
	return 0;
} 
