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

#define DEBUG 1

typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


const int MAXCD = 1e5 + 5;

struct CentroidD{
	vector< int > graph[MAXCD]; 
	int sub[MAXCD];
	int cpar[MAXCD];

	void add_edge(int a, int b){
		graph[a].pb(b);
		graph[b].pb(a);
	}

	void dfs(int cur, int parent){
		sub[cur] = 1;
		for(int i = 0; i < sz(graph[cur]); ++i){
			int to = graph[cur][i];
			if(to != parent && cpar[to] == -1){
				dfs(to, cur);
				sub[cur] += sub[to];
			}
		}
	}

	void decompose(int cur, int parent, int sb, int prevc){
		for(int i = 0; i < sz(graph[cur]); ++i){
			int to = graph[cur][i];
			if(to != parent && cpar[to] == -1 && (2 * sub[to] > sb)){
				decompose(to, cur, sb, prevc);
				return;
			}
		}
		cpar[cur] = prevc;
		for(int i = 0; i < sz(graph[cur]); ++i){
			int to = graph[cur][i];
			if(cpar[to] == -1){
				dfs(to, - 1);
				decompose(to, cur, sub[to], cur);
			}
		}
	}
	
	void init(int start){
		for(int i = 0; i < MAXCD; ++i) cpar[i] = -1;
		dfs(start, - 1);
		decompose(start, -1, sub[start], -2);
	}
};

CentroidD CD;

vector < int > ad[MAXN]; 
char color[MAXN]; 

void dfs(int u, int level){
	color[u] = 'A' + level; 
	for(int i = 0; i < sz(ad[u]); ++i){
		int v = ad[u][i];
		dfs(v, level + 1);
	}
}

int main(){
	int n; scanf("%d", &n);
	int a, b;
	for(int i = 0; i < n - 1; ++i){
		scanf("%d %d", &a, &b);
		--a, --b;
		CD.add_edge(a, b); 
	}
	int idx = -1;
	CD.init(0); 
	for(int i = 0; i < n; ++i){
		int p = CD.cpar[i];
		if(p == -2){
			idx = i;
			continue;
		}
		ad[p].pb(i);
	}
	for(int i = 0; i < n; ++i) color[i] = 0;
	dfs(idx, 0);
	for(int i = 0; i < n; ++i){
		if(i) printf(" "); 
		printf("%c", color[i]); 
	}
	return 0;
} 
