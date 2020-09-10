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
const int  INF = 2e9;
const ll LINF = 1e16 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int ans[1005];
vector< int > v[1005];
vector< int > vv1[1005];

int main(){

	int n;
	cin >> n;
	for(int i = 0; i <= 9; ++i){
		for(int j = 1;j <= n; ++j){
			if( j & (1 << i)){
				v[i].pb(j);
			}
			else vv1[i].pb(j);
		}
	}

	for(int i = 0; i < 1001; ++i) ans[i] = INF;
	for(int i = 0; i < 10; ++i){
		int len = int(v[i].size());
		if(len == 0) continue;
		cout << len << endl;
		cout.flush();
		for(int j  = 0; j < len; ++j){
			if(j) cout << " ";
			cout << v[i][j];
		}
		cout << endl;
		cout.flush();
		int x;
		for(int j = 1; j <= n; ++j){
			cin >> x;
			bool ok = 0;
			for(int r = 0; r < len; ++r)
			if(v[i][r] == j){
				ok = 1;
				break;
			}
			if(!ok) ans[j] = min(ans[j], x);
		}
	}
	
	for(int i = 0; i < 10; ++i){
		int len = int(vv1[i].size());
		if(len == 0) continue;
		cout << len << endl;
		cout.flush();
		for(int j  = 0; j < len; ++j){
			if(j) cout << " ";
			cout << vv1[i][j];
		}
		cout << endl;
		cout.flush();
		int x;
		for(int j = 1; j <= n; ++j){
			cin >> x;
			bool ok = 0;
			for(int r = 0; r < len; ++r){
				if(vv1[i][r] == j){
					ok = 1;
					break;
				}	
				
			}
			if(!ok) ans[j] = min(ans[j], x);
		}
	}
	
	cout << "-1" << endl;
	cout.flush();
	for(int i = 1; i <= n; ++i){
		if(i > 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	cout.flush();

	return 0;
} 
