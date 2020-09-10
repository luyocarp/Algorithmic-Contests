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
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ini, fin;
	for(int i = 0 ; i < n ; ++i){
		if(s[i] == 'G') ini = i;
		else if(s[i] == 'T') fin = i;
	}
	
	if(fin  < ini) swap(ini, fin);
	bool ok = 1;
	for(int i = ini ; i < fin ; i += k){
		if(s[i] == '#'){
			ok = 0;
			break;
		}
	}

	if((fin - ini) % k != 0) ok = 0;
	
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}	
