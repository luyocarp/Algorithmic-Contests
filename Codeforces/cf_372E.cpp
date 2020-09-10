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


int a[1001];
int b[1001];
int c[1001];
int d[1001];
double x[1001];
double y[1001];
vector< pair< pair< double, double >, double > > v;
int le[MN];
int ri[MN];
int r[MN];


bool eq(int idx){
	double rx1 = v[idx - 1].itm1;
	double ry1 = v[idx - 1].itm2;
	double rx2 = v[idx].itm1;
	double ry2 = v[idx].itm2;
	if(abs(rx1 - rx2) < EPS && abs(ry1 - ry2) < EPS) return 1;
	else return 0;
}

bool tcmp(pair< pair<double, double>, double > d1, pair< pair<double, double>, double > d2){
	if(abs(d1.itm1 - d2.itm1) > EPS) return d1.itm1 < d2.itm1;
	if(abs(d1.itm2 - d2.itm2) > EPS) return d1.itm2 < d2.itm2;
	if(abs(d1.itm3 - d2.itm3) > EPS) return d1.itm3 < d2.itm3;
	return 0;
}

bool cmp(double x1, double x2){
	if(abs(x1 - x2) < EPS) return 0;
	if(x1 < x2) return 1;
	else return 0;
}

int main(){
	fast_io();
	int n; cin >> n;
	double mm;
	for(int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i = 0; i < n; ++i){
		x[i] = (1.0 * a[i] * b[i] * d[i] * d[i]) / (sqr(1.0 * a[i] * d[i]) + sqr(1.0 * b[i] * c[i]));
		y[i] = (1.0 * c[i] * d[i] * b[i] * b[i]) / (sqr(1.0 * a[i] * d[i]) + sqr(1.0 * b[i] * c[i]));
	}

	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			double rx = x[i] + x[j];
			double ry = y[i] + y[j];
			if(abs(x[i] - x[j]) < EPS) mm = 1e50;
			else mm = (y[i] - y[j]) / (x[i] - x[j]); 
			v.pb(mt(rx, ry, mm)); 
		}
	}

	sort(all(v), tcmp);
	v.pb(mt(-1e50, -1e50, -1e50));
	#ifdef DEBUG
	for(int i = 0; i < v.size(); ++i){
		cout << "(" << v[i].itm1 << ", " << v[i].itm2 << ", " << v[i].itm3 << ")" << endl;
	}
	#endif
	int _sz = 1;
	le[_sz - 1] = 0;
	for(int i = 1; i < v.size(); ++i){
		if(!eq(i)){
			ri[_sz - 1] = i - 1;
			le[_sz] = i;
			++_sz;
		}
	}
	--_sz;
	ll ans = 0;
	ll u = 1;
	ll ret = 0;
	assert(ri[_sz - 1] == int(v.size()) - 2);
	vector < int > ss;
	vector< double > ww;
	for(int i = 0; i < _sz; ++i){
		ss.clear();
		ww.clear(); 
		for(int j = le[i]; j <= ri[i]; ++j) ww.pb(v[j].itm3);
		ss.pb(1);
		int last = 0;
		for(int j = 1; j < ww.size(); ++j){
			if(abs(ww[j] - ww[last]) < EPS){
				int len = ss.size();
				ss[len - 1]++;
			} 
			else{
				last = j;
				ss.pb(1); 
			}	
		}
		ret = 0;
		u = 1;
		for(int j = 0; j < ss.size(); ++j){
			u = (u * (ss[j] + 1)) % MOD;
			ret += ss[j]; 
		}
		ans = (ans + u - ret - 1) % MOD;
	}
	if(ans < 0) ans += MOD; 
	cout << ans << endl; 
	return 0;
} 
