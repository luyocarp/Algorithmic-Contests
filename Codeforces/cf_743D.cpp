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


ll t1[2 * MAXN];
ll dp[2 * MAXN];
ll a[2 * MAXN];
vector< int > ad[2 * MAXN];
bool used[2 * MAXN];
bool mk[2 * MAXN];
int padre[2 * MAXN];

void dfs(int u, int p){
	ll ret = a[u];
	padre[u] = p;
	used[u] = 1;
	for(int i = 0;i < int(ad[u].size()); ++i){
		int v = ad[u][i];
		if(v == p) continue;
		if(!used[v]){
			dfs(v, u);
		}
		ret += dp[v];
	}
	dp[u] = ret;
}


void dfs2(int u){
	mk[u] = 1;
	t1[u] = dp[u];
	for(int i = 0; i < int(ad[u].size()); ++i){
		int v = ad[u][i];
		if(v == padre[u]) continue;
		if(!mk[v]) dfs2(v);
		t1[u] = max(t1[v], t1[u]);
		t1[u] = max(t1[u], dp[u]);		
	}
	
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%I64d", &a[i]);
	}
	int u, v;
	for(int i = 0; i < n - 1; ++i){
		scanf("%d %d", &u, &v);
		--u, --v;
		ad[u].pb(v);
		ad[v].pb(u);
	}

	dfs(0, 0);
	dfs2(0);
	
	ll ans = -LINF;
	bool ok = 0;
	for(int i = 0; i < n; ++i){
		ll m1 = -LINF, m2 = -LINF;
		int can = 0;
		for(int j = 0; j < int(ad[i].size()); ++j){
			int v = ad[i][j];
			if(v == padre[i]) continue;
			++can;
			if(t1[v] > m1){
				m2 = m1;
				m1 = t1[v];
			}
			else{
				m2 = max(m2, t1[v]);
			}
		} 
		
		if(can >= 2){
			ok = 1;
			ans = max(ans, m1 + m2);
		}
	}
	if(!ok) printf("Impossible\n");
	else printf("%I64d\n", ans);

	return 0;
}	 
