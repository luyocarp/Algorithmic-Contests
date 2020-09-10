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
const int  INF = 1e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;

int t[40];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};


pair< ii , ii > mc(int x, int y, int z, int w){
	return mp(mp(x, y), mp(z, w));
}


set< pair< ii, ii > > al;
int mark[1000][1000];

ii get(int d){
	if(d == 0) return mp(1, 7);
	if(d == 1) return mp(0, 2);
	if(d == 2) return mp(1, 3);
	if(d == 3) return mp(2, 4);
	if(d == 4) return mp(3, 5);
	if(d == 5) return mp(6, 4);
	if(d == 6) return mp(7, 5);
	if(d == 7) return mp(0, 6);
}

int main(){
	fast_io();
	int n; 
	cin >> n;
	for(int i = 0; i < n ; ++i) cin >> t[i];
	int x = 400, y = 400;
	queue< pair< ii, ii > > q;
	q.push(mc(400, 400, 0, 0));
	mark[400][400] = 1;
	int nx, ny;
	int dd;
	while(!q.empty()){
		pair< ii, ii > tt = q.front();
		q.pop();
		int cx = (tt.fst).fst;
		int cy = (tt.fst).snd;
		int d = (tt.snd).fst;
		int r = (tt.snd).snd;
		mark[cx][cy] = 1;
		for(int i = 0; i < t[r]; ++i){
			nx = cx + i * dx[d];
			ny = cy + i * dy[d];
			mark[nx][ny] = 1;
		}
		
		ii dd = get(d);
		int d1 = dd.fst;
		int d2 = dd.snd;
		int mx = nx;
		int my = ny;
		nx = mx + dx[d1];	
		ny = my + dy[d1];
		if((r + 1) < n && !al.count(mc(nx, ny, d1, r + 1))){
			q.push(mc(nx, ny, d1, r + 1));
			al.insert(mc(nx, ny, d1, r + 1));
		}
		nx = mx + dx[d2];
		ny = my + dy[d2];
		if((r + 1) < n && !al.count(mc(nx, ny, d2, r + 1))){
			q.push(mc(nx, ny, d2, r + 1));
			al.insert(mc(nx, ny, d2, r + 1));
		}		
	}
	
	int ans = 0;
	for(int i = 0; i < 1000; ++i){
		for(int j = 0; j < 1000; ++j){
			if(mark[i][j]) {
				++ans;
			}
		}
	}	
	cout << ans << endl;
	return 0;
} 
