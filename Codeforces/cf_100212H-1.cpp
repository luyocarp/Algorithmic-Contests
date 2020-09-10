#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define REP(i,x,y) for(int (i) = (x) ; (i) < (y) ; ++(i))
#define REPIT(it,A) for(__typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
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
//const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18; // Be carfeul with LINF, this value is appropiate
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 2;


string ss[55];
bool visit[55][55];
vector< ii > border;
int n, m;
int perimeter = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

inline int dist(int u, int v){
	if(v >= u) return v - u;
	else return perimeter + u - v;
}

inline int nxt(int u, int k){
	return (k + u + perimeter) % perimeter;
}

inline int movement(int u){
	int nxtu = (u + 1) % perimeter;
	int disx = border[nxtu].fst - border[u].fst, disy = border[nxtu].snd - border[u].snd;
	if(disx == 0 && disy == 1) return 1;
	else if(disx == 0 && disy == -1) return -1;
	else if(disx == -1 && disy == 0) return 2;
	else if(disx == 1 && disy == 0) return -2;
}


inline int ok(int u, int v){
	if(u >= 0 && u < n && v >= 0 && v < m){
		if(ss[u][v] == '*') return 1;
	}
	return 0;
}


void dfs(int r, int c){
	if(ss[r][c] == '*' || visit[r][c]) return;
	visit[r][c] = 1;
	for(int d = 0 ; d < 4 ; ++d){
		int rr = r + dx[d], cc = c + dy[d];
		if(rr >= 0 && rr < n && cc >= 0 && cc < m){
			dfs(rr,cc);
		}
	}
}

bool conexo(){
	for(int i = 0 ; i < n ; ++i){
		dfs(i,0);
		dfs(i,m-1);
	}
	for(int j = 0 ; j < m ; ++j){
		dfs(0,j);
		dfs(n-1,j);
	}	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(ss[i][j] == '.' && !visit[i][j]) return 0;
		}
	}	
	return 1;
}

inline int counting(int u, int v){
	return ok(u - 1, v - 1) + ok(u - 1, v) + ok(u, v - 1) + ok(u, v);
}

bool ninterior(int u, int v, int uu, int vv){
	int tmp1 = 0, tmp2 = 0;
	if((uu == u + 1) && (vv == v)){
		if(v > 0 && v < m) tmp1 = ss[u][v-1] == '*', tmp2 = ss[u][v] == '*';
		else if(v == 0) tmp1 = ss[u][v] == '*';
		else if(v == m) tmp2 = ss[u][v-1] == '*';
		if(tmp1 + tmp2 != 1) return 0;
		else return 1;
	}
	else if((uu == u) && (vv == v + 1)){
		if(u > 0 && u < n) tmp1 = ss[u-1][v] == '*', tmp2 = ss[u][v] == '*';
		else if(u == 0) tmp1 = ss[u][v] == '*';
		else if(u == n) tmp2 = ss[u-1][v] == '*';
		if(tmp1 + tmp2 != 1) return 0;
		else return 1;
	}
	else if((uu == u) && (vv == v - 1)){
		if(u > 0 && u < n) tmp1 = ss[u-1][v-1] == '*', tmp2 = ss[u][v-1] == '*';
		else if(u == 0) tmp1 = ss[u][v-1] == '*';
		else if(u == n) tmp2 = ss[u-1][v-1] == '*';
		if(tmp1 + tmp2 == 1) return 1;
		else return 0;
	}
	else if((uu == u - 1) && (vv == v)){
		if(v > 0 && v <  m) tmp1 = ss[u-1][v-1] == '*', tmp2 = ss[u-1][v] == '*';
		else if(v == 0) tmp1 = ss[u-1][v] == '*';
		else if(v == m) tmp2 = ss[u-1][v-1] == '*';
		if(tmp1 + tmp2 == 1) return 1;
		else return 0;
	}
}

void build_border(){
	set< ii > candidates;
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j <= m ; ++j){
			int tmp = counting(i,j);
			if(tmp != 0 && tmp != 4) candidates.insert(mp(i,j));
		}
	}
	ii cur = *(candidates.begin());
	border.pb(cur);
	candidates.erase(cur);
	while(!candidates.empty()){
		bool ter = 0;
		for(int d = 0 ; d < 4 ; ++d){
			int cx = cur.fst + dx[d], cy = cur.snd + dy[d];
			if(candidates.count(mp(cx,cy)) && ninterior(cur.fst, cur.snd, cx,cy)){
				cur = mp(cx,cy);
				candidates.erase(cur);
				border.pb(cur);
				ter = 1;
				break;
			}
		}
	}	
}


bool congruent(int fptr, int sptr, int yo){
	for(int i = 0 ; i < yo ; ++i){
		if(movement(fptr) + movement(nxt(sptr, -1)) != 0) return 0;
		else{
			fptr = nxt(fptr, 1);
			sptr = nxt(sptr, -1);
		}
	}
	return 1;
}


int main(){
	freopen("tilings.in", "r", stdin);
	freopen("tilings.out", "w", stdout);
	fast_io();
	n = 0;
	string s;
	m = 0;
	while(cin >> s){
		ss[n] = s;
		++n;
		m = max(int(s.size()), m);
	}
	// m columns
	for(int i = 0 ; i < n ; ++i){	
		int len = int(ss[i].size());
		for(int j = 0 ; j < m - len ; ++j){
			ss[i] += '.';			
		}
	}
	
	// n rows, m columns
	#ifdef DEBUG
	cout << "Or after trying to complete" << endl;
	cout << "Let's take a look at the grid" << endl;
	for(int i = 0 ; i < n ; ++i){
		cout << ss[i] << endl;
	}
	cout << "END OF GRID" << endl;
	#endif
	bool right = conexo();
	if(!right){
		cout << "NO" << endl;
	}
	else{	
		// Find the border here
		build_border();
		perimeter = int(border.size());
		#ifdef DEBUG
		debug(perimeter);
		for(int i = 0 ; i < perimeter ; ++i){
			cout << "(" << border[i].fst << "," << border[i].snd << ")" << endl;
		}	
		#endif
		if(perimeter % 2 != 0){
			cout << "NO" << endl;
		}
		else{
			bool ok = 0;
			bool flg0 = 0;
			// If there are 6 pts ,fix 3, get the other latero
			for(int i = 0 ; i < perimeter ; ++i){
				for(int j = 0 ; j < perimeter ; ++j){
					for(int k = 0 ; k < perimeter ; ++k){
					ok = 1;
					int dij = dist(i,j);
					int djk = dist(j,k);
					int dik = dist(i, k);
					if(dij == 0 || djk == 0 || dik == 0) continue;
					if(dij + djk >= perimeter/2) continue;
					if(dij + djk != dik) continue;
					int dd = perimeter/2 - dij - djk;
					int D = nxt(k, dd);
					int E = nxt(D, dij);
					int F = nxt(E, djk);
					int fptr = i, sptr = D;
					ok = congruent(i,E,dij) && congruent(j,F,djk) && congruent(k, i, dd);
					if(ok) flg0 = 1;					
					}	
				}
			}
			bool ok4 = 0, flg1 = 0;
			// Now, if there are 4 pts, fix 2 and get the other
			for(int i = 0; i < perimeter ; ++i){
				for(int j = 0 ; j < perimeter ; ++j){
					ok4 = 0;
					int dij = dist(i,j);
					int dd = perimeter/2 - dij;
					if(dij == 0) continue;
					if(dij >= perimeter/2) continue;
					int D = nxt(j, perimeter/2 - dij);
					int E = nxt(D, dij);
					ok4 = congruent(i,E, dij) && congruent(j,i,dd);
					if(ok4) flg1 = 1;					
				}
				
			}
			if(flg0 || flg1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	return 0;
}
