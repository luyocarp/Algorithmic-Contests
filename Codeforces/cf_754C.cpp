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


string user[111];
vector< int > v[111];
set< int > g[111];
map< string, int > mapa;
bool already[111];
string ff[111];
string ans[111];
set< int > :: iterator it;

int main(){
	fast_io();
	int n, casos;
	cin >> casos;
	int m;
	string s;
	string u, t;
	int idx;
	string tmp;
	string st;
	string uu;
	string useless;
	while(casos--){
		mapa.clear();
		for(int i = 0; i < 111; ++i){
			v[i].clear(); g[i].clear();
			already[i] = 0;
		}
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> user[i];
			mapa[user[i]] = i;
		}
		cin >> m;
		getline(cin, useless);
		for(int i = 0; i < m; ++i){
			getline(cin, s);
			int len = int(s.size());
			for(int j = 0; j < len; ++j){
				if(s[j] == ':'){
					idx = j;
					break;
				}
			}
			u = s.substr(0, idx);
			t = s.substr(idx + 1, len - idx - 1);
			ff[i] = t;
			tmp = "";
			for(int j = 0; j < t.size(); ++j){
				if(t[j] == '.' || t[j] == '!' || t[j] == ',' || t[j] == '?' || t[j] == ' ') tmp.pb(' ');
				else tmp.pb(t[j]);
				
			}
			string ss = "";
			for(int j = 0; j < tmp.size(); ++j){
				if(tmp[j] == ' '){
					if(mapa.count(ss)) v[i].pb(mapa[ss]);
					ss = "";
				}
				else{
					ss.pb(tmp[j]);
				}
			}
			if(ss != "" && mapa.count(ss) ) v[i].pb(mapa[ss]);
			if(u[0] != '?'){
				int ulen = u.size();
				uu = u;
				ans[i] = uu;
				already[i] = 1;
				if(i >= 1) v[i - 1].pb(mapa[uu]);
				if(i + 1 < m) v[i + 1].pb(mapa[uu]);
			}	
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < v[i].size(); ++j){
				g[i].insert(v[i][j]);
			}
			v[i].clear();
			for(it = g[i].begin(); it != g[i].end(); ++it){
				v[i].pb(*it);
			}
		}
		int ok = 1;
		while(1){
			int ya = 0;
			bool ret = 0;
			for(int i = 0; i < m; ++i){
				if(g[i].size() == n){
					ret = 1;
					break;
				}
			}
			if(ret){
				ok = 0;
				break;
			}
			for(int i = 0; i < m; ++i){
				if(g[i].size() == (n - 1) && !already[i]){
					ret = 1;
				}
			}
			if(!ret){
				ok = 2;
				break;
			}	
			for(int i = 0; i < m; ++i){
				if(already[i]){
					++ya;
				}
			}
			if(ya == m) break;
			for(int i = 0; i < m; ++i){
				if(g[i].size() == (n - 1)){
					for(int j = 0; j < n; ++j){
						if(!g[i].count(j) && !already[i]){
							ans[i] = user[j];
							already[i] = 1;
							if(i >= 1) g[i - 1].insert(j);
							if(i + 1 < m) g[i + 1].insert(j);
							break;
						}
					}
				}
			}
		}
		
		if(ok == 0) cout << "Impossible" << endl;
		else{
			if(ok == 2){
				for(int i = 0; i < m; ++i){
					for(int j = 0; j < n; ++j){
						if(!g[i].count(j) && !already[i]){
							ans[i] = user[j];
							if(i + 1 < m) g[i + 1].insert(j);
							break;
						}
					}
				}
			}
			for(int i = 0; i < m; ++i){
				cout << ans[i] << ":" << ff[i] << endl;
			}
		}		
		
	}
	return 0;
} 
