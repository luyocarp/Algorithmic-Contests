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


int tot = 0;
int tt[1001];
int a[1001];
int ed[1001];
bool used[1001];
vector< int > ad[1001];
ii rr[1001];


int C2(int x){
	return (x * (x - 1))/ 2;
}

void dfs(int u, int id){
	used[u] = 1;
	tot++;
	ed[id] += int(ad[u].size());
	for(int i = 0; i < ad[u].size(); ++i){
		int v = ad[u][i];
		if(!used[v]){
			dfs(v, id);
		}
	}
}

int main(){
	fast_io();
	int n, m, k; cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) cin >> a[i],--a[i];
	int x, y;
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		--x, --y;
		ad[x].pb(y);
		ad[y].pb(x);
	}

	int cnt = 0;
	for(int i = 0; i < k; ++i){
		dfs(a[i], cnt);
		tt[cnt++] = tot;
		tot = 0;
	}

	for(int i = 0; i < n; ++i){
		if(!used[i]){
			dfs(i, cnt);
			tt[cnt++] = tot;
			tot = 0;
		}
	}

	int ans = 0;
	for(int i = 0; i < cnt; ++i) rr[i] = mp(tt[i], ed[i]);
	sort(rr, rr + k);
	for(int i = k; i < cnt; ++i){
		rr[k - 1].fst += rr[i].fst;
		rr[k - 1].snd += rr[i].snd;
	}
	for(int i = 0; i < k; ++i){
		rr[i].snd /= 2;
		ans += C2(rr[i].fst) - rr[i].snd;
	}	
	cout << ans << endl;
	return 0;
}
