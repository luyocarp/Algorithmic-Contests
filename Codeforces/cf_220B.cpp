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

#define EPS 1e-7

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

const int MAX = 330;

tri query[MAXN];
unordered_map< int, int > mapa;
int ans[MAXN]; 
int a[MAXN]; 
int cur = 0;

bool cmp(tri r1, tri r2){
	if((r1.itm1 / MAX) != (r2.itm1 / MAX)) return (r1.itm1 / MAX) < (r2.itm1 / MAX);
	else return r1.itm2 < r2.itm2;
}

inline void erase(int pos){
	int x = a[pos];
	if(mapa[x] == x) cur--;
	mapa[x]--;
	if(mapa[x] == x) cur++; 	
}

inline void insert(int pos){
	int x = a[pos];
	if(mapa[x] == x) cur--;
	mapa[x]++;
	if(mapa[x] == x) cur++; 
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int x, y; 
	for(int q = 0; q < m; ++q){
		scanf("%d %d", &x, &y);
		--x, --y;
		query[q] = mt(x, y, q);
	}
	sort(query, query + m, cmp); 
	int l = 0, r = -1;
	for(int who = 0; who < m; ++who){
		while(r < query[who].itm2){
			++r;
			insert(r);
		}
		while(r > query[who].itm2){
			erase(r);
			--r;
		}
		while(l < query[who].itm1){
			erase(l);
			++l;
		}
		while(l > query[who].itm1){
			--l;
			insert(l);
		}
		ans[query[who].itm3] = cur; 
	}
	for(int who = 0; who < m; ++who) printf("%d\n", ans[who]); 
 	return 0;
} 
