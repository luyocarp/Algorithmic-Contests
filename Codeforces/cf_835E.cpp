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
 

vector< int > v[20];
bool isSame[20];

int found(int bit, int x) {
	int r;
	int lo = 0, hi = sz(v[bit]) - 1;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		cout << "? " << mid + 1;
		for(int i = 0; i <= mid; ++i) {
			cout << " " << v[bit][i];
		}
		cout << endl;
		cin >> r;
		if(r == 0 || r == x) {
			lo = mid + 1;
		}
		else hi = mid;
	}
	return v[bit][hi];
}

int main() {
	fast_io();
	int n; cin >> n;
	int x, y; cin >> x >> y;
	int id = 0;
	for(int i = 0; i < 20; ++i) {
		if(n & (1 << i)) id = i;
	} 
	
	for(int mask = 1; mask <= n; ++mask) {
		for(int i = 0; i <= id; ++i) {
			if(mask & (1 << i)) v[i].pb(mask);
		}
	}

	int r;
	for(int i = 0; i <= id; ++i) {
		cout << "? ";
		cout << sz(v[i]); 
		for(int z : v[i]) cout << " " << z;
		cout << endl;
		cin >> r;
		if(r == 0 || r == x) isSame[i] = 1;
		else isSame[i] = 0;
	}
	
	int bit = -1;
	for(int i = 0; i <= id; ++i) {
		if(!isSame[i]) bit = i;
	}

	int idx1 = 0, idx2 = 0;
	idx1 = found(bit, x);
	for(int i = 0; i <= id; ++i) {
		int cur_bit = (idx1 >> i) & 1;
		if(isSame[i]) {
			if(cur_bit) idx2 |= (1 << i);
		}
		else {
			if(!cur_bit) idx2 |= (1 << i);
		}
	}
	if(idx1 > idx2) swap(idx1, idx2);
	cout << "! " << idx1 << " " << idx2 << endl;
	return 0;
} 
