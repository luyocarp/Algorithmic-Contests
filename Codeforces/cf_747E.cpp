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


vector< int > v;
int cur[MN];
int h[MN];
vector< int > ad[MN];
string ans[MN];
int cnt = 0;
int dist[MN];
bool vis[MN];
int padre[MN];
vector< int > capa[MN];

void dfs(int u, int de){
	vis[u] = 1;
	capa[de].pb(u);
	for(int i = 0; i < ad[u].size(); ++i){
		int w = ad[u][i];
		if(!vis[w]){
			dfs(w, de + 1);
		}
	}
	
}


int num(string s){
	int x = 0;
	for(int i = 0; i < s.size(); ++i){
		x *= 10;
		x += (s[i] - '0');
	}
	return x;
}

int main(){
	fast_io();
	string s; cin >> s;
	s.pb(',');
	int n = int(s.size());
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == ','){
			cnt++;
			if(cnt % 2 == 0) v.pb(i);
		}
	}

	int r = v.size();
	int st = 0;
	int id = 0;
	
	for(int i = 0; i < r; ++i){
		string t = "";
		int p = st;
		int y;
		if(i == 0) y = 0;
		else y = v[i - 1] + 1;
		for(int j = y; j < v[i]; ++j){
			if(s[j] == ','){
				p = j;
				break;
			}
			t.pb(s[j]);
		}
		ans[id] = t;
		t = "";
		for(int j = p + 1; j < v[i]; ++j){
			if(s[j] == ','){
				break;
			}
			t.pb(s[j]);
		}
		int tr = num(t);
		h[i] = tr;
		cur[i] = id;
		++id;
	}
	
	int last = 0, f = 0;
	int ac = 0;
	for(int i = 1; i < r; ++i){
		
		if(h[ac] > 0){
			ad[ac].pb(i);
			padre[i] = ac;
			--h[ac];
			ac = i;
		}
		else{
			while(1){
				ac = padre[ac];
				if(h[ac] > 0) break;
				if(ac == padre[ac] && h[ac] == 0){
					break;	
				}
			}
			if(ac == padre[ac] && h[ac] == 0){
					ac = i;
					padre[i] = i;
					continue;
			}
			ad[ac].pb(i);
			--h[ac];
			padre[i] = ac;
			ac = i;
		}
	}

	for(int i = 0; i < id; ++i){
		if(!vis[i]) dfs(i, 0);
	}

	int m = -1;
	for(int i = 0; i < MN; ++i){
		if(!capa[i].empty()) m = i;
	}
	
	cout << m + 1 << endl;
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j < capa[i].size(); ++j){
			cout << ans[capa[i][j]] << " ";
		}
		cout << endl;
	}
	return 0;
} 
