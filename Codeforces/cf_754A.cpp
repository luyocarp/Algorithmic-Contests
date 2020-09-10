#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
//#define ones(x) __builtin_popcount(x)
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
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


ll a[105];
ll parc[105];
int main(){
	fast_io();
	int n; cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i + 1];
	}
	for(int i = 1; i <= n; ++i) parc[i] = parc[i - 1] + a[i];
	
	if(parc[n] != 0){
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << " " << n << endl;
	}
	else{
		bool ok = 0;
		int id = -1;
		for(int i = 1; i <= n; ++i){
			if(parc[i] != 0){
				id = i;
				ok = 1;
				break;
			}
		}
		if(ok){
		cout << "YES" << endl;
		cout << 2 << endl;
		cout << 1 << " " << id << endl;
		cout << id + 1 << " " << n << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
} 
