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

typedef vector<int> VI;
typedef ll T;
typedef vector<T> VT;
typedef vector<VT> VVT;


ll binpow(ll a, ll n){
	if(n == 0) return 1;
	if(n % 2 == 1) return a * binpow(a, n - 1) % MOD;
	ll tmp = binpow(a, n / 2);
	return tmp * tmp % MOD;
}


inline ll inverso(ll x){
	return binpow(x, MOD - 2);	
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
		irow[i] = pj;
		icol[i] = pk;

		T c = inverso(a[pk][pk]);
		det *= a[pk][pk];
		a[pk][pk] = 1;
		for (int p = 0; p < n; p++){
			a[pk][p] = (a[pk][p] * c) % MOD;
			if(a[pk][p] < 0) a[pk][p] += MOD;
		}
		for (int p = 0; p < m; p++){
			b[pk][p] = (b[pk][p] * c) % MOD;
			if(b[pk][p] < 0) b[pk][p] += MOD;
		}
		for (int p = 0; p < n; p++) if (p != pk) {
			c = a[p][pk];
			a[p][pk] = 0;
			for (int q = 0; q < n; q++){
				a[p][q] = (a[p][q] - a[pk][q] * c) % MOD;
				if(a[p][q] < 0) a[p][q] += MOD;
			}
			for (int q = 0; q < m; q++){
				b[p][q] = (b[p][q] - b[pk][q] * c) % MOD;
				if(b[p][q] < 0) b[p][q] += MOD;
			}    
		}
	}

	for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
		for (int k = 0; k < n; k++) 
			swap(a[k][irow[p]], a[k][icol[p]]);
	}
	return det;
}


ll CTE = 987654321;

vector< ll > v[111];
int l[111];
int r[111];
int mid[111];


int near(ll x){
	int d0 = x;
	int d1 = MOD - x;
	if(d0 < d1) return 1;
	else return 0;
}

ll gcd(ll a, ll b){
	a = abs(a); b = abs(b);
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	fast_io();
	int n, m; cin >> n >> m;
	if(m == 1){
		cout << "A";
		for(int i = 0; i < n; ++i) cout << " 1";
		cout << endl;
		return 0;
	}
	//ask
	cout << "?";
	for(int i = 0; i < n; ++i) cout << " " << 1;
	cout << endl;
	
	for(int i = 0; i <= n; ++i) v[i].resize(n);
	for(int i = 0; i < n; ++i){
		cin >> v[0][i];
		if(v[0][0] == CTE) exit(0);
	}
	
	for(int i = 1; i <= n; ++i){
		// ask 
		cout << "?";
		for(int j = 1; j <= n; ++j){
			cout << " ";
			if(i == j) cout << 2;
			else cout << 1;
		}
		cout << endl;
		
		for(int j = 0; j < n; ++j){
			cin >> v[i][j];	
			if(v[i][0] == CTE) exit(0);
		}		
	}

	// Get the values of the base
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < n; ++j){
			v[i][j] -= v[0][j];
		}	
	}

	for(int i = 1; i <= n; ++i){
		ll g = 0;
		for(int j = 0; j < n; ++j){
			g = gcd(g, v[i][j]);	
		}
		for(int j = 0; j < n; ++j) v[i][j] /= g;
	}


	for(int i = 1; i <= n; ++i){
		l[i] = 1; 
		r[i] = m + 1;
	}
	
	VVT A, B;
	A.resize(n);
	B.resize(n);
	for(int i = 0; i < n; ++i){
		A[i].resize(n);
		B[i].resize(1);
		for(int j = 0; j < n; ++j){
			A[i][j] = v[j + 1][i];
			A[i][j] %= MOD;
			if(A[i][j] < 0) A[i][j] += MOD;
		}
	}
	for(int q = 0; q < 17; ++q){
		for(int i = 1; i <= n; ++i){
			mid[i] = (l[i] + r[i]) / 2;
		}
		// ask
		cout << "?";
		for(int i = 1; i <= n; ++i){
			cout << " ";
			cout << mid[i];
		}
		cout << endl;

		for(int i = 0; i < n; ++i){
			cin >> B[i][0];
			if(B[0][0] == CTE) exit(0);
			B[i][0] %= MOD;
			if(B[i][0] < 0) B[i][0] += MOD;
		}
		GaussJordan(A, B);
		for(int i = 0; i < n; ++i){
			B[i][0] %= MOD;
			if(B[i][0] < 0) B[i][0] += MOD;
			if(B[i][0] == 0){
				l[i + 1] = mid[i + 1];
				r[i + 1] = mid[i + 1] + 1;
			}
			else if(near(B[i][0])) r[i + 1] = mid[i + 1]; 
			else l[i + 1] = mid[i + 1];
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				A[i][j] = v[j + 1][i];
				A[i][j] %= MOD;
				if(A[i][j] < 0) A[i][j] += MOD;
			}
		}
	}

	cout << "A"; 
	for(int i = 1; i <= n; ++i){
		cout << " ";
		cout << l[i] ;
		assert(l[i] + 1 == r[i]);
	}
	cout << endl;
	return 0;
} 
