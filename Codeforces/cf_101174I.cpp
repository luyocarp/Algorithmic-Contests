#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
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
typedef long long ll;
typedef pair<ll,ll> ill;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ill, ll> tri;
typedef unsigned int uint;

const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


typedef vector<int> VI;
typedef int T;
typedef vector<T> VT;
typedef vector<VT> VVT;


int inverso[15];


int rref(VVT &a) {
  int n = a.size();
  int m = a[0].size();
  int r = 0;
  for (int c = 0; c < m && r < n; c++) {
    int j = r;
    for (int i = r+1; i < n; i++) 
      if (a[i][c] > a[j][c]) j = i;
    if (a[j][c] == 0) continue;
    swap(a[j], a[r]);
    T s = inverso[a[r][c]];
    for (int j = 0; j < m; j++) a[r][j] = (a[r][j] * s) % 13;;
    for (int i = 0; i < n; i++) if (i != r) {
      T t = a[i][c];
      for (int j = 0; j < m; j++){
		a[i][j] = (a[i][j] - t * a[r][j]) % 13;
		if(a[i][j] < 0) a[i][j] += 13;
      }
    }
    r++;
  }
  return r;
}

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;
	
	for (int i = 0; i < n; i++) {
		int pj = -1, pk = -1;
		for (int j = 0; j < n; j++) if (!ipiv[j])
			for (int k = 0; k < n; k++) if (!ipiv[k])
				if (pj == -1 || a[j][k] > a[pj][pk]) { 
					pj = j; pk = k; 
				}
		if (a[pj][pk] == 0) { 
			cerr << "Matrix is singular." << endl; exit(0); 
		}
		ipiv[pk]++;
		swap(a[pj], a[pk]);
		swap(b[pj], b[pk]);
		if (pj != pk) det *= -1;
		det = (det + 13) % 13;
		irow[i] = pj;
		icol[i] = pk;

		T c = inverso[a[pk][pk]];
		det *= a[pk][pk];
		det %= 13;
		a[pk][pk] = 1;
		for (int p = 0; p < n; p++) a[pk][p] = (a[pk][p] * c) % 13;
		for (int p = 0; p < m; p++) b[pk][p] = (b[pk][p] * c) % 13;
		for (int p = 0; p < n; p++) if (p != pk) {
			c = a[p][pk];
			a[p][pk] = 0;
			for (int q = 0; q < n; q++){
				a[p][q] = (a[p][q] - a[pk][q] * c) % 13;
				a[p][q] = (a[p][q] + 13) % 13;	
			}
			for (int q = 0; q < m; q++){
				b[p][q] = (b[p][q] - b[pk][q] * c) % 13;
				b[p][q] = (b[p][q] + 13) % 13; 
			}
     
		}
	}

	for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
		for (int k = 0; k < n; k++) 
			swap(a[k][irow[p]], a[k][icol[p]]);
	}
	return det;
}


int cnt = 0;
int x[505][808];
int fila[505][808];
int c[505];
ii edges[222];
map< ii, int > mapa;


int getid(int r, int s){
	if(r > s) swap(r, s);
	if(!mapa.count(mp(r, s))){
		edges[cnt] = mp(r, s);
		mapa[mp(r, s)] = cnt;
		++cnt;
		return cnt - 1;
	}
	else return mapa[mp(r, s)];
}

int dist[202];
vector<ii> ad[202];  // Edge is (target, weight)
priority_queue< ii, vector<ii>, greater<ii> > pq;

void dijkstra(int s){
	dist[s] = 0;
	pq.push(mp(0,s));
	while(!pq.empty()){
		ii data = pq.top(); 
		pq.pop();
		int d = data.first;
		int u = data.second;
		if(d  > dist[u]) continue;
		for(int j = 0; j < ad[u].size(); j++){
			ii v = ad[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(mp(dist[v.first],v.first));
			}
		}
	}
}

int main(){

	for(int i = 1; i < 13; ++i){
		for(int j = 1; j < 13; ++j){
			if((i * j) % 13 == 1){
				inverso[i] = j;
				break;
			}
		}
	}
	fast_io();
	int n, a, r, t;
	cin >> n >> a >> r >> t;
	--a, --r;
	VVT A, B;
	int d, p;
	for(int trips = 0; trips < t; ++trips){
		cin >> d >> p;
		for(int i = 0; i < p; ++i){
			cin >> x[trips][i];
			--x[trips][i];
		}
		for(int i = 0; i < p - 1; ++i){
			int city1 = x[trips][i];
			int city2 = x[trips][i + 1];
			int id = getid(city1, city2);
			fila[trips][id] = (fila[trips][id] + 1) % 13;
		}
		c[trips] = d;
	}

	VVT tmp;
	tmp.resize(t);
	for(int i = 0; i < t; i++){
		tmp[i].resize(cnt + 1);
		for(int j = 0; j < cnt; ++j) tmp[i][j] = fila[i][j];
		tmp[i][cnt] = c[i];
	}
	
	rref(tmp);
	
	int valido = t;
	for(int i = 0; i < t; ++i){
		bool ok = 0;
		for(int j = 0; j < cnt; ++j){
			if(tmp[i][j] != 0) ok = 1;
		}
		if(!ok){
			valido = i;
			break; 
		}
	}
	assert(valido == cnt);
	A.resize(valido);
	B.resize(cnt);
	for(int i = 0; i < valido; ++i){
		A[i].resize(cnt);
		B[i].resize(1);
		B[i][0] = tmp[i][cnt];
		for(int j = 0; j < cnt; ++j){
			A[i][j] = tmp[i][j];	
		}
	}

	GaussJordan(A, B);
	for(int i = 0; i < cnt; ++i){
		int u = edges[i].fst, v = edges[i].snd;
		int w = B[i][0];
		w %= 13;
		if(w < 0) w += 13;
		ad[u].pb(mp(v, w));
		ad[v].pb(mp(u, w));
	}
	for(int i = 0; i < 202; ++i) dist[i] = INF / 2;
	dijkstra(a);
	cout << dist[r] << endl;
	return 0;
} 
