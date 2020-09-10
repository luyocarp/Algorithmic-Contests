#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
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

const double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN =  1e5 + 5;
const int MN = 1e6 + 2;


char s[200005];
char t[200005];
char car[] = {'A', 'C', 'G', 'T'};
vector< int > entra[200005];
vector< int > sale[200005];

int lens, lent; 
vector< int > a, b, c;
int kf; 
int match[5][200005];

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

const int FMAX = 820000;
struct FFT {
	cpx data[FMAX];
	cpx roots[FMAX];
	int rev[FMAX];
	int s, n;

	void init(int pw){
		s = pw;
		n = (1 << s);
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

FFT pga, pgb;

void solve(int cc, int k){
	for(int i = 0; i < lens; ++i){
		entra[i].clear(); 
		sale[i].clear();
	}
	set< int > cur; 
	cur.clear(); 
	for(int i = 0; i < lens; ++i){
		if(s[i] == car[cc]){
			int der = max(0, i - k);
			int esq = min(lens - 1, i + k);
			entra[der].pb(i);
			sale[esq].pb(i); 
		}	 
	}
	a.clear();
	b.clear();
	c.clear(); 
	a.resize(lens); 
	for(int i = 0; i < lens; ++i) a[i] = 0; 
	for(int i = 0; i < lens; ++i){
		if(!entra[i].empty()){
			for(auto x : entra[i]) cur.insert(x);
		}
		if(!cur.empty()) a[i] = 1;
		if(!sale[i].empty()){
			for(auto x : sale[i]) cur.erase(x); 
		}
	}
	
	b.resize(lent);
	for(int i = 0; i < lent; ++i){
		if(t[i] == car[cc]) b[i] = 1;
		else b[i] = 0;
	}
	
	reverse(all(b)); 

	a.resize(kf);
	b.resize(kf);
	c.resize(kf);
	
	for(int i = lens; i < kf; ++i) a[i] = 0;
	for(int i = lent; i < kf; ++i) b[i] = 0;

	REP(i,0,kf) pga.data[i] = cpx(a[i], 0);
	pga.transform();
	REP(i,0,kf) pgb.data[i] = cpx(b[i], 0);
	pgb.transform();
	REP(i,0,kf) pga.data[i] = pga.data[i] * pgb.data[i];
	pga.transform(true);

	REP(i,0,kf) c[i] = (int) (pga.data[i].a + 0.5);
	for(int i = lent - 1; i < lens + lent - 1; ++i) match[cc][i - lent + 1] = c[i]; 
	
}

int main(){
	int k; scanf("%d %d %d", &lens, &lent, &k);
	scanf("%s", s); scanf("%s", t);
	int pw = 0;
	while((1 << pw) < lens + lent) pw++;
	pga.init(pw);
	pgb.init(pw);
	kf = (1 << pw);
	for(int j = 0; j < 4; ++j) solve(j, k);
	int ans = 0;
	int ret = 0; 
	for(int i = 0; i < lens - lent + 1; ++i){
		ans = 0;
		for(int j = 0; j < 4; ++j) ans += match[j][i];
		if(ans == lent) ++ret;
	}
	printf("%d\n", ret); 
	return 0;
} 
