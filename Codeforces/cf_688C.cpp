#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
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
typedef pair<ii, int> tri;
typedef pair<int,bool> ib;
typedef unsigned int uint;


const double PI = acos(-1);
const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7; 
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;


vector< int > ad[MAXN];
int color[MAXN];

bool bicolor(int u){
	color[u] = 0;
	queue< int > q;
	q.push(u);
	while(!q.empty()){
		int frente = q.front();
		q.pop();
		for(int i = 0 ; i < ad[frente].size() ; ++i){
			int v = ad[frente][i];
			if(color[v] == color[frente]) return 0;
			if(color[v] == -1){
				color[v] = 1 - color[frente];
				q.push(v);
			}
		}	
	}
	return 1;
}

int main(){
	fast_io();
	int n, m; cin >> n >> m;
	int x, y;
	for(int i = 0 ; i < m ; ++i){
		cin >> x >> y;
		--x, --y;
		ad[x].pb(y);
		ad[y].pb(x);
	}

	for(int i = 0 ; i < n ; ++i) color[i] = -1;
	for(int i = 0; i < n ; ++i){
		if(color[i] == -1){
			bool ok = bicolor(i);
			if(!ok){
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	int n0 = 0;
	for(int i = 0 ; i < n ; ++i){
		if(color[i] == 0) ++n0;
	}

	cout << n0 << endl;
	for(int i = 0 ; i < n ; ++i)
	if(color[i] == 0) cout << i + 1 << " ";
	cout << endl;

	cout << n - n0 << endl;
	for(int i = 0 ; i < n ; ++i)
	if(color[i] == 1) cout << i + 1 << " ";
	cout << endl;

	return 0;

}
