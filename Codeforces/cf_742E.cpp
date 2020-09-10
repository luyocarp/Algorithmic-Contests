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


vector< int > ad[2 * MAXN];
int color[2 * MAXN];
ii couple[MAXN];


bool bicolor(int u){
	color[u] = 0;
	queue< int > q;
	q.push(u);
	while(!q.empty()){
		int frente = q.front();
		q.pop();
		for(int i = 0; i < ad[frente].size(); ++i){
			int v = ad[frente][i];
			if(color[v] == -1){
				color[v] = 1 - color[frente];
				q.push(v);
			}
			else if(color[v] == color[frente]) return 0;
		}
	}
	return 1;

}


int main(){
	fast_io();
	int n; cin >> n;
	int x, y;
	for(int i = 0; i < n; ++i){
		cin >> x >> y;
		--x, --y;
		ad[x].pb(y);
		ad[y].pb(x);
		couple[i] = mp(x, y);
	}

	for(int i = 0; i < n; ++i){
		ad[2 * i].pb(2 * i + 1);
		ad[2 * i + 1].pb(2 * i);
	}
	
	for(int i = 0; i < 2 * n; ++i) color[i] = -1;
	
	bool ok = 1;
	for(int i = 0; i < 2 * n; ++i){
		if(color[i] == -1){
			ok &= bicolor(i);
		}
	}

	if(!ok) cout << -1 << endl;
	else{
		for(int i = 0; i < n; ++i){
			ii pareja = couple[i];
			cout << color[pareja.fst] + 1 << " " << color[pareja.snd] + 1 << endl;
		}
	}
	return 0;
} 
