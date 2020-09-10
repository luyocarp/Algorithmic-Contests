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

int used[2 * MAXN]; 
vector< int > spanning;
vector< int > ad[2 * MAXN];  
vector< int > ans[2 * MAXN]; 

inline int get(int x, int y){
	if(x % y == 0) return x / y; 
	else return x / y + 1; 
}


void dfs(int u, int padre){
	used[u] = 1;
	spanning.pb(u); 
	for(int i = 0; i < ad[u].size(); ++i){
		int v = ad[u][i]; 
		if(v == padre) continue;
		if(!used[v]){
			dfs(v, u); 
			spanning.pb(u); 
		}
	}
}

int main(){
	int n, m, k; scanf("%d %d %d", &n, &m, &k); 
	int x, y; 
	set< ii > sw; 
	sw.clear(); 
	for(int i = 0; i < m; ++i){ 
		scanf("%d %d", &x, &y);
		--x, --y;
		if(x == y) continue; 
		if(sw.count(mp(x, y))) continue; 
		ad[x].pb(y);
		ad[y].pb(x);
		if(x > y) swap(x, y);
		sw.insert(mp(x, y)); 
	}
	
	dfs(0, 0); 

	int len = int(spanning.size());
	int allowed = get(2 * n, k); 
	int cur_rob = 0;
	int pos = 0; 
	while(pos < len){ 
		for(int i = pos; i < min(pos + allowed, len); ++i){
			ans[cur_rob].pb(spanning[i]); 
		}
		pos += allowed; 
		cur_rob++; 
	}

	for(int i = cur_rob; i < k; ++i){
		ans[i].pb(1); 
	}

	for(int i = 0; i < k; ++i){
		int cur_len = int(ans[i].size());
		printf("%d", cur_len); 
		for(int j = 0; j < cur_len; ++j)
		printf(" %d", ans[i][j] + 1); 
		printf("\n");  
	}	
	return 0;
} 
