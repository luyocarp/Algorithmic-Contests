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


int get(int a, int n){
	int ret = n * n - a * a;
	if(ret < 0) return -1;
	int u = int(sqrt(ret));
	u = max(0, u - 2);
	while(1){
		if(u * u > ret) break;
		if(u * u == ret){
			return u;
		}
		++u;
	}
	return -1;
}


int main(){
	fast_io();
	int a, b; cin >> a >> b;
	int x1, x2, y1, y2;
	bool ok = 0;
	for(int i = -a; i <= a; ++i){
		for(int j = -b; j <= b; ++j){
			x1 = i;	
			x2 = j;
			y1 = get(x1, a);
			y2 = get(x2, b);
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) continue;
			if(x1 == x2 || y1 == y2) continue;
			if(y1 != -1 && y2 != -1 && (y1 * y2 == -x1 * x2 )){
				ok = 1;
				break;
			}
			y1 = -y1;
			if(x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) continue;
			if(x1 == x2 || y1 == y2) continue;
			if(y1 != -1 && y2 != -1 && (y1 * y2 == -x1 * x2 )){
				ok = 1;
				break;
			}
			
		}
		if(ok) break;
	}
	if(!ok) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << x1 << " " << y1 << endl;
		cout << x2 << " " << y2 << endl;
	}
	return 0;
} 
