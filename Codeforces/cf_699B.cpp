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

string s[1001];
int p_fila[1001];
int p_col[1001];

int get_fila(int idx){
	if(idx == 0) return p_fila[0];
	return p_fila[idx] - p_fila[idx-1];
}

int get_col(int idx){
	if(idx == 0) return p_col[0];
	return p_col[idx] - p_col[idx-1];
}

int main(){
	fast_io();
	int n, m; cin >> n >> m;
	for(int i = 0 ; i < n ; ++i) cin >> s[i];
	int nbomb = 0;
	for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < m ; ++j)
	if(s[i][j] == '*') nbomb++;
	
	for(int j = 0 ; j < n ; ++j){
		if(s[j][0] == '*') p_fila[0]++;
	}
	for(int i = 1 ; i < m ; ++i){
		p_fila[i] = p_fila[i-1];
		for(int j = 0 ; j < n ; ++j)
		if(s[j][i] == '*') p_fila[i]++;
	}

	for(int i = 0 ; i < m ; ++i){
		if(s[0][i] == '*') p_col[0]++;
	}
	for(int i = 1 ; i < n ; ++i){
		p_col[i] = p_col[i-1];
		for(int j = 0 ; j < m ; ++j)
		if(s[i][j] == '*') p_col[i]++;
	}

	for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < m ; ++j){
		int ret = get_fila(j) + get_col(i);
		if(s[i][j] == '*') --ret;
		if(ret == nbomb){
			cout << "YES" << endl;
			cout << i + 1 << " " << j + 1 << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;

}
