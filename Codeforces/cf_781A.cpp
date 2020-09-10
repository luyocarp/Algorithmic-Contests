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


vector< int > ad[2 * MAXN]; 
int color[2 * MAXN]; 

void dfs(int u, int padre){
	int x = 1;
	for(int i = 0; i < ad[u].size(); ++i){
		int v = ad[u][i];
		if(v == padre) continue;
		while(x == color[u] || x == color[padre]) x++; 
		color[v] = x;
		x++; 
		dfs(v, u);		
	}
}

int main(){
	fast_io();
	int n; cin >> n;
	int u, v; 
	for(int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		--u, --v;
		ad[u].pb(v);
		ad[v].pb(u);
	}		
	
	int dm = 0;
	int idx = -1;
	for(int i = 0; i < n; ++i){
		int len = int(ad[i].size());
		if(len > dm){
			dm = len;
			idx = i;
		}
	}
	
	color[idx] = 1;
	for(int i = 0; i < ad[idx].size(); ++i){
		int v = ad[idx][i];
		color[v] = color[idx] + i + 1;
	}

	for(int i = 0; i < ad[idx].size(); ++i){
		int v = ad[idx][i];
		dfs(v, idx); 
	}

	cout << dm + 1 << endl;
	for(int i = 0; i < n; ++i) cout << color[i] << " "; 
	cout << endl;
	return 0;
} 
