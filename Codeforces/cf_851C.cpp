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
typedef vector<int> vi;
typedef unsigned int ui;
typedef vector<ii> vii;


const long double PI = acos(-1);
const int  INF = 2e9 + 5;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;


const int MAX = 1024;

ll a[MAX];
ll b[MAX];
ll c[MAX];
ll d[MAX];
ll e[MAX];
ll dist[MAX][MAX];

ll Get(int i, int j) {
	ll u = sqr(a[i] - a[j]);
	ll v = sqr(b[i] - b[j]);
	ll w = sqr(c[i] - c[j]);
	ll t = sqr(d[i] - d[j]);
	ll s = sqr(e[i] - e[j]);
	return u + v + w + t + s;
}

int mark[MAX];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) continue;
			dist[i][j] = Get(i, j);
		}
	}
  	ll u, v, w;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			for(int r = j + 1; r < n; ++r) {
				u = dist[i][j];
				v = dist[j][r];
				w = dist[i][r];
				if(w < u + v) {
					mark[j] = 1;
				}
				if(u < v + w) {
					mark[r] = 1;
				}
				if(v < u + w) {
					mark[i] = 1;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(!mark[i]) ++ans;
	}

	cout << ans << endl;
	for(int i = 0; i < n; ++i) {
		if(!mark[i]) cout << i + 1 << endl;
	}
	return 0;
} 
