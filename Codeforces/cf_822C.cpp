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


const long double PI = acos(-1);
const int  INF = 2e9 + 5;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;


map< ii, int > mapa;
map< int, vector< int > > entra, sale;

int main(){
	fast_io();
	int n, x; cin >> n >> x;
	int l, r, c;
	for(int i = 0; i < n; ++i){
		cin >> l >> r >> c;
		if(mapa.count(mp(l, r))) mapa[mp(l, r)] = min(mapa[mp(l, r)], c);
		else mapa[mp(l, r)] = c;
	}

	vector< tri > v;
	for(auto it = mapa.begin(); it != mapa.end(); ++it){
		int l1 = (*it).fst.fst;
		int r1 = (*it).fst.snd;
		int c1 = (*it).snd;
		v.pb(mt(l1, r1, c1));
	}	

	set< int > sw;
	for(int i = 0; i < sz(v); ++i){
		tri tmp = v[i];
		entra[tmp.itm1].pb(i);
		sale[tmp.itm2].pb(i);
		sw.insert(tmp.itm1);
		sw.insert(tmp.itm2);
	}

	map< int, int > afuera;
	int ans = INF;
	for(auto it = sw.begin(); it != sw.end(); ++it){
		int val = *it;
		for(int i = 0; i < sz(entra[val]); ++i){
			int ind = entra[val][i];
			int costo = v[ind].itm3;
			int ini = v[ind].itm1;
			int fin = v[ind].itm2;
			int falta = x - (fin - ini + 1);
			if(afuera.count(falta)){
				ans = min(ans, costo + afuera[falta]);
			}
		}

		for(int i = 0; i < sz(sale[val]); ++i){
			int ind = sale[val][i];
			int costo = v[ind].itm3;
			int ini = v[ind].itm1;
			int fin = v[ind].itm2;
			if(afuera.count(fin - ini + 1)){
				afuera[fin - ini + 1] = min(afuera[fin - ini + 1], costo);
			}
			else afuera[fin - ini + 1] = costo;
		}
	}

	if(ans != INF) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
} 
