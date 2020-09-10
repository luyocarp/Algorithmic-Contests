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
const ll MOD = 1e9 + 9;


const int MAX = 3e5 + 2;
const int BLOCK = 2048; // length of a block
const int NB = 150; // number of blocks (MAX / BLOCK)

struct Query {
	int op, l, r;
};

Query query[MAX];
int a[MAX];
int pref[MAX];

int Fib[MAX];
int prefib[MAX];
int l[NB]; //id of block's beg
int r[NB]; //id of block's end
pair< int, int > toupd[BLOCK];
int sz;
int active[MAX];
ll inc[MAX];
int n, m;

void update() {
	for(int i = 0; i < n; ++i) active[i] = 0;
	for(int i = 0; i < n; ++i) inc[i] = 0;
	for(int i = 0; i < sz; ++i) {
		int esq = toupd[i].first;
		int der = toupd[i].second;
		active[esq] = 1;
		if(der + 1 < n) {
			active[der + 1] = 1;
		}
		if(der + 2 < n) {
			active[der + 2] = 1;
		}
	}
	
	for(int j = 0; j < sz; ++j) {
		int le = toupd[j].first, ri = toupd[j].second;
		if(le <= 0 && 0 <= ri) {
			inc[0] = (inc[0] + Fib[0]) % MOD;
		}	
		if(1 < n && le <= 1 && 1 <= ri) {
			inc[1] = (inc[1] + Fib[1-le]) % MOD;
		}	
	}

	for(int i = 2; i < n; ++i) {
		if(!active[i]) {
			inc[i] = (inc[i-1] + inc[i-2]) % MOD;
		}
		else {
			for(int j = 0; j < sz; ++j) {
				int le = toupd[j].first, ri = toupd[j].second;
				if(le <= i && i <= ri) {
					inc[i] = (inc[i] + Fib[i-le]) % MOD;
				}
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		a[i] = (a[i] + inc[i]) % MOD;
		if(a[i] < 0) a[i] += MOD;
	}

	pref[0] = a[0];
	for(int i = 1; i < n; ++i) {
		pref[i] = (pref[i-1] + a[i]) % MOD;
	}	
	sz = 0;
}

inline int GetFib(int l, int r) {
	if(l == 0) return prefib[r];
	else return (prefib[r] - prefib[l-1] + MOD) % MOD;
}

inline int Get(int l, int r) {
	if(l == 0) return pref[r];
	else return (pref[r] - pref[l-1] + MOD) % MOD;
}

int main() {
	Fib[0] = 1;
	Fib[1] = 1;
	for(int i = 2; i < MAX; ++i) Fib[i] = (Fib[i-1] + Fib[i-2]) % MOD;
	prefib[0] = Fib[0];
	for(int i = 1; i < MAX; ++i) prefib[i] = (prefib[i-1] + Fib[i]) % MOD;

	fast_io();
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	pref[0] = a[0];
	for(int i = 1; i < n; ++i) pref[i] = (pref[i-1] + a[i]) % MOD;

	int option, le, ri;
	for(int q = 0; q < m; ++q) {
		cin >> option >> le >> ri;
		--le, --ri;
		query[q].op = option;
		query[q].l = le;
		query[q].r = ri;
	}

	for(int i = 0; i < NB; ++i) 
		l[i] = m + 1, r[i] = -1;
	
	for(int q = 0; q < m; ++q) {
		l[q / BLOCK] = min(l[q / BLOCK], q);
		r[q / BLOCK] = max(r[q / BLOCK], q);
	}

	sz = 0;
	for(int idblock = 0; idblock < NB; ++idblock) {
		if(r[idblock] == -1) break;
		int st = l[idblock];
		int ed = r[idblock];
		for(int i = st; i <= ed; ++i) {
			int le = query[i].l, ri = query[i].r;
			if(query[i].op == 1) {
				toupd[sz] = mp(le, ri);
				++sz;
			}
			else {
				ll ans = Get(le, ri);
				for(int j = 0; j < sz; ++j) {
					int leinter = toupd[j].first;
					int riinter = toupd[j].second;
					if(leinter <= le && riinter >= ri) {
						ans = (ans + GetFib(le-leinter, ri - leinter)) % MOD;
					}	
					else if(leinter <= le && riinter < ri && riinter >= le) {
						ans = (ans + GetFib(le-leinter, riinter - leinter)) % MOD;
					}
					else if(leinter > le && riinter >= ri && leinter <= ri) {
						ans = (ans + GetFib(0, ri - leinter)) % MOD;
					}			
					else if(leinter > le && riinter < ri) {
						ans = (ans + GetFib(0, riinter - leinter)) % MOD;
					}
				}
				if(ans < 0) ans += MOD;
				cout << ans << endl;
			}
		}	
		update();//sz = 0
	}	
	return 0;
} 
