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


typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e4 + 5;
const int MN = 1e6 + 2;


char s1[5 * MAXN];
char s2[5 * MAXN];
int match[5][5][10 * MAXN]; 


struct cpx {
	double a, b;
	cpx() : a(0), b(0) { }
	cpx(double a, double b) : a(a), b(b) { }
	const cpx operator+(const cpx &c) const
		{return cpx(a + c.a, b + c.b);}
	const cpx operator-(const cpx &c) const
		{return cpx(a - c.a, b - c.b);}
	const cpx operator*(const cpx &c) const
		{return cpx(a*c.a - b*c.b, a*c.b + b*c.a);}
};

const int FMAX = 264000;
class FFT {

public:
	cpx data[FMAX];
	cpx roots[FMAX];
	int rev[FMAX];
	int s, n;

	void init(int pw){
		s = pw;
		n = (1 << s);
		for(int i = 0; i < n; ++i) rev[i] = 0;
		REP(i,0,n) REP(j,0,s) 
			if ((i & (1 << j)) != 0)
					rev[i] += (1 << (s-j-1));
		roots[0] = cpx(1, 0);
		cpx mult = cpx(cos(2*PI/n), sin(2*PI/n));
		REP(i,1,n+1) roots[i] = roots[i-1] * mult;
	}

	cpx temp[FMAX];
	void transform(bool inverse = false){
		REP(i,0,n) temp[i] = data[rev[i]];
		REP(i,0,n) data[i] = temp[i];
		REP(i,1,s+1){
			int m = (1 << i), md2 = m / 2;
			int start = 0, increment = (1 << (s-i));
			if (inverse) {
				start = n;
				increment *= -1;
			}
			cpx t, u;
			for (int k = 0; k < n; k += m) {
				int index = start;
				REP(j,k,md2+k){
					t = roots[index] * data[j+md2];
					index += increment;
					data[j+md2] = data[j] - t;
					data[j] = data[j] + t;
				}
			}
		}
		if (inverse) REP(i,0,n){
			data[i].a /= n;
			data[i].b /= n;
		}
	}
};

FFT Pola, Polb;
vector< int > a, b, c;
int n;
int k;

void solve(int x, int y) {
	for (int i = 0; i < 2 * n; ++i) a[i] = b[i] = 0;
	for (int i = 0; i < n; ++i)
		a[i] = (('A' + x) == s1[i]);	
	for (int i = 0; i < n; ++i)
		b[i] = b[i + n] = (('a' + y) == s2[i]);
	a.resize(k);
	b.resize(k);
	c.resize(k); 
	for (int i = 2 * n; i < k; ++i) a[i] = b[i] = 0;
	for (int i = 0; i < k; ++i) {
		Pola.data[i] = cpx(a[i], 0);
		Polb.data[i] = cpx(b[i], 0);
	}
	Pola.transform();
	Polb.transform();
	for (int i = 0; i < k; ++i) Pola.data[i] = Pola.data[i] * Polb.data[i];
	Pola.transform(true);
	for (int i = 0; i < k; ++i) c[i] = int (Pola.data[i].a + 0.5);
	for (int i = 0; i < 2 * n; ++i) match[x][y][i] = c[i];
}

int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	n = strlen(s1);
	reverse(s2, s2 + n); 
	int pw = 0;
	while ((1 << pw) < (4 * n - 1)) ++pw;
	k = 1 << pw;
	Pola.init(pw);
	Polb.init(pw);
	a.resize(2 * n);
	b.resize(2 * n);
	for (int i = 0; i < 5; ++i) 
		for (int j = 0; j < 5; ++j) 
			solve(i, j);
	int ans = 0;	
	vector< int >v;
	v.resize(5);
	for (int i = 0; i < 5; ++i) v[i] = i;
	do {
		int ret = 0;
		for(int i = 0; i < 2 * n; ++i) {
			ret = 0;
			for (int j = 0; j < 5; ++j) {
				ret += match[j][v[j]][i];
			}
			ans = max(ans, ret);
		}
	} while(next_permutation(all(v)));

	printf("%d\n", n - ans); 
	return 0;
} 
