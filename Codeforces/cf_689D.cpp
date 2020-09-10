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


int aa[2 * MAXN];
int bb[2 * MAXN];
int rmqmin[20][2 * MAXN];
int rmqmax[20][2 * MAXN];


int getmin(int x, int y){
	if(bb[x] > bb[y]) return y;
	else return x;
}

int getmax(int x, int y){
	if(aa[x] > aa[y]) return x;
	else return y;	
}


int get_rmqmax(int x, int y){
	//a's
	int ss = int(log2(y - x + 1));
	return getmax(rmqmax[ss][x], rmqmax[ss][y - (1 << ss) + 1]);
}

int get_rmqmin(int x, int y){
	int ss = int(log2(y - x + 1));
	return getmin(rmqmin[ss][x], rmqmin[ss][y - (1 << ss) + 1]);
}


int main(){
	int n; scanf("%d", &n);
	for(int i = 0 ; i < n ; ++i) scanf("%d",&aa[i]);
	for(int i = 0 ; i < n ; ++i) scanf("%d",&bb[i]);
	
	for(int i = 0 ; i < n ; ++i) rmqmin[0][i] = i;// from b's
	for(int i = 0 ; i < n ; ++i) rmqmax[0][i] = i;// from a's

	// Be careful with the order of the for's
	for(int j = 1 ; j < 20 ; ++j){
		for(int i = 0 ; i + (1 << j) <= n ; ++i){
			rmqmin[j][i] = getmin(rmqmin[j-1][i], rmqmin[j-1][i + (1 << (j-1))]);
			rmqmax[j][i] = getmax(rmqmax[j-1][i], rmqmax[j-1][i + (1 << (j-1))]);
		}
	}

	ll ans = 0;
	for(int i = 0 ; i < n  ; ++i){
		int lo = i, hi = n - 1;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			if(aa[get_rmqmax(i, mid)] >= bb[get_rmqmin(i, mid)]) hi = mid;
			else lo = mid + 1;
		}
		int ret1 = lo;
		if(aa[get_rmqmax(i, ret1)] < bb[get_rmqmin(i, ret1)]) ret1 = -1;

		lo = i, hi = n - 1;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			if(aa[get_rmqmax(i, mid)] > bb[get_rmqmin(i, mid)]) hi = mid;
			else lo = mid + 1;
		}

		int ret2 = lo; 
		if(aa[get_rmqmax(i, ret2)] <= bb[get_rmqmin(i,ret2)]) ret2 = -1;

		if(ret1 == -1) continue;
		if(ret2 == -1){
			ans += n - ret1;
		}
		else{
			ans += ret2 - ret1;
		}
		
	}

 	printf("%I64d\n", ans);
	return 0;
}
