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
const int MN = 1e6 + 5;



int r[MAXN]; 
vector< ii > ad[MAXN]; 
vector< int > sw[MAXN]; 
int color[MAXN]; 

bool bicolor(int u){
	queue< int > q;
	q.push(u);
	color[u] = 0; 
	while(!q.empty()){
		int frente = q.front();
		q.pop();
		for(int i = 0; i < ad[frente].size(); ++i){
			int v = ad[frente][i].fst;
			int c = ad[frente][i].snd;
			if(color[v] == -1){
				if(color[frente] == 0){
					if(c == 0) color[v] = 0;
					else color[v] = 1;
				}
				else{
					if(c == 0) color[v] = 1;
					else color[v] = 0; 
				}
				q.push(v);
			}
			else{
				if(c == 0){
					if(color[v] != color[frente]) return 0;
				}	
				else{
					if(color[v] == color[frente]) return 0; 
				}	
			}
		}	
	}
	return 1; 
}

int main(){
	int n, m; 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", &r[i]);
	int x; 
	int y;
	for(int i = 0; i < m; ++i){
		scanf("%d", &x);
		for(int j = 0; j < x; ++j){
			scanf("%d", &y);
			--y;
			sw[y].pb(i); 
		}
	}

	for(int i = 0; i < n; ++i){
		assert(sw[i].size() == 2); 
		int u = sw[i][0];
		int v = sw[i][1];
		if(r[i] == 1){
			ad[u].pb(mp(v, 0));
			ad[v].pb(mp(u, 0));
		}
		else{
			ad[u].pb(mp(v, 1));
			ad[v].pb(mp(u, 1));
		}			
	}

	for(int i = 0; i < m; ++i) color[i] = -1;
	bool ok = 1;
	for(int i = 0; i < m; ++i){
		if(color[i] == -1){
			bool ret = bicolor(i);
			if(!ret) {
				ok = 0;
				break; 
			}
		}
	}

	if(ok) printf("YES");
	else printf("NO"); 
	return 0;
} 
