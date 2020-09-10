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
const int  INF = 1e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int a[2 * MAXN];
int d[2 * MAXN];

int main(){
	fast_io();
	int n; cin >> n;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> d[i];
		sum += a[i];
	}
	int curlo = -INF, curhi = INF;
	if(d[n - 1] == 1){
		curlo = 1900;
	}
	else{
		curhi = 1899;
	}
	for(int i = n - 2; i >= 0; --i){
		curlo -= a[i];
		curhi -= a[i];
		if(d[i] == 1){
			curlo = max(curlo, 1900);
			if(curhi < 1900){
				cout << "Impossible" << endl;
				return 0;
			}
	
		}
		else{
			curhi = min(curhi, 1899);
			if(curlo >= 1900){
				cout << "Impossible" << endl;
				return 0;
			}
		}
		if(curlo > curhi){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	
	if(2 * curhi > INF){
		cout << "Infinity" << endl;
		return 0;
	}
	cout << curhi + sum << endl;
	return 0;
} 
