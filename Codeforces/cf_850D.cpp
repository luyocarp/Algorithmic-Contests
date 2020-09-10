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


int a[1 << 5];
int dp[1 << 5][1 << 6][1 << 11];
pair< ii, int > path[1 << 5][1 << 6][1 << 11];
int cnt[1 << 5];
pair< int, int > torneo[1 << 6];
int ad[1 << 6][1 << 6];


int go(int tipo, int k, int sum) {
	if(tipo < 0) return 0;
	if(sum * 2 < k * (k - 1)) return 0;
	if(k == 1) {
		if(tipo > 0) return 0;
		if(sum != a[0]) return 0;
		else return 1;		
	}
	if(dp[tipo][k][sum] != -1) return dp[tipo][k][sum];
	int value1 = 0, value2 = 0;
	value1 = go(tipo, k - 1, sum - a[tipo]);
	if(tipo > 0) value2 = go(tipo - 1, k - 1, sum - a[tipo]);

	if(value1) {
		path[tipo][k][sum] = mt(tipo, k - 1, sum - a[tipo]);
	}
	else if(value2){
		path[tipo][k][sum] = mt(tipo - 1, k - 1, sum - a[tipo]);
	}	
	return dp[tipo][k][sum] = value1 || value2;
}


int main() {
	fast_io();
	int m; cin >> m;
	for(int i = 0; i < m; ++i) cin >> a[i];
	sort(a, a + m);
	for(int i = 0; i < 1 << 5; ++i) 
		for(int j = 0; j < 1 << 6; ++j) 
			for(int r = 0; r < 1 << 11; ++r) {
				dp[i][j][r] = -1;
				path[i][j][r] = mt(0, 0, 0);
			}
	int ans = -1;
	for(int i = 1; i <= 62; ++i) {
		if(go(m - 1, i, i * (i - 1) / 2)) {
			ans = i;
			break;
		}
	}

	if(ans == -1) {
		cout << "=(" << endl;
		return 0;
	}

	int sx = m - 1, sy = ans, sz = ans * (ans - 1) / 2;
	while(sy != 0) {
		cnt[sx] ++;
		tri tmp = path[sx][sy][sz];
		sx = tmp.itm1;
		sy = tmp.itm2;
		sz = tmp.itm3;
	}

	int player = 0;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			torneo[player] = mp(a[i], player);
			++player;
		}
	}

	assert(player == ans);

	for(int it = 0; it < ans; ++it) {
		sort(torneo + it, torneo + ans);
		int victorias = torneo[it].fst;
		int id1 = torneo[it].snd;
		for(int i = it + 1; i <= it + victorias; ++i) {
			int id2 = torneo[i].snd;
			ad[id1][id2] = 1;
		}
		for(int i = it + victorias + 1; i < ans; ++i) {
			int id2 = torneo[i].snd;
			ad[id2][id1] = 1;
			torneo[i].fst --;
		}
	}

	cout << ans << endl;
	for(int i = 0; i < ans; ++i) {
		for(int j = 0; j < ans; ++j) {
			cout << ad[i][j];
		}
		cout << endl;
	}	
	return 0;
} 
