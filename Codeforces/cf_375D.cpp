#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(auto it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd.fst
#define itm4 snd.snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) int(v.size())


typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const long double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int c[MAXN];
int v[MAXN];
int k[MAXN];
int tin[MAXN];
int tout[MAXN];
int true_ans[MAXN];
int cnt[MAXN];
int freq[MAXN]; 
int rev[MAXN]; 
vector< int > ad[MAXN]; 
pair< ii, ii > queries[MAXN]; 
vector< int > toans[300]; 


int BLOCK = 450; 
int timer = 0;

void dfs(int u, int padre){
	rev[timer] = u;
	tin[u] = timer++; 
	for(int w : ad[u]){
		if(w == padre) continue;
		dfs(w, u);
	}
	tout[u] = timer - 1;
}

void add(int pos){
	cnt[c[pos]] ++;
	freq[cnt[c[pos]]] ++;
}

void remove(int pos){
	freq[cnt[c[pos]]] --;
	cnt[c[pos]] --;
}


int main(){
	fast_io();
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> c[i];
	int a, b;
	for(int i = 0; i < n - 1; ++i){
		cin >> a >> b;
		--a, --b;
		ad[a].pb(b);
		ad[b].pb(a);
	}
	for(int i = 0; i < m; ++i){
		cin >> v[i] >> k[i];
		--v[i];
	}
	dfs(0, 0);
	
	//r, l, k, id
	for(int i = 0; i < m; ++i){
		queries[i].itm1 = tout[v[i]];
		queries[i].itm2 = tin[v[i]]; 
		queries[i].itm3 = k[i];
		queries[i].itm4 = i; 
	}
	
	sort(queries, queries + m); 
	for(int i = 0; i < m; ++i)
		toans[queries[i].itm2 / BLOCK].pb(i);

	int esq = 0, der = -1;
	for(int i = 0; i < 300; ++i){
		if(!toans[i].empty()){
			for(int x : toans[i]){
				int required = queries[x].itm3;
				while(der < queries[x].itm1){
					der++;
					add(rev[der]);
				}
				while(der > queries[x].itm1){
					remove(rev[der]);
					--der;					
				}
				while(esq < queries[x].itm2){
					remove(rev[esq]);
					++esq;
				}
				while(esq > queries[x].itm2){
					--esq;
					add(rev[esq]); 
				}
				true_ans[queries[x].itm4] = freq[required];
			}			
		}
	}

	for(int i = 0; i < m; ++i) 
		cout << true_ans[i] << endl; 
	return 0;
} 
