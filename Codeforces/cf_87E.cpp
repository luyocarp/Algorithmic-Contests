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

#define DEBUG 1

typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const long double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;

#define EPS 1e-12

struct PT { 
  ll x, y; 
  PT() {}
  PT(ll x, ll y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (ll c)     const { return PT(x*c,   y*c  ); }
  bool operator == (const PT &p) const{ return (x == p.x) && (y == p.y); }
  bool operator != (const PT &p) const{ return (x != p.x) || (y != p.y); }
};

ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

ll cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

inline bool compare(PT a, PT b){
	if(a.y < b.y) return 1;
	if(a.y == b.y) return a.x < b.x;
	return 0;
}

vector< PT > minkow_sum(const vector< PT >& a, const vector< PT >& b){
	vector< PT > out;
	out.clear();
	int lena = int(a.size());
	int lenb = int(b.size());
	int i = 0, j = 0;
	for(int q = 0; q < lena; ++q) if(compare(a[q], a[i])) i = q;
	for(int q = 0; q < lenb; ++q) if(compare(b[q], b[j])) j = q;
	ll pr;
	int nxti, nxtj;	
	do{
		out.pb(a[i] + b[j]);
		nxti = (i + 1) % lena;
		nxtj = (j + 1) % lenb; 
		pr = cross(a[nxti] - a[i], b[nxtj] - b[j]);
		if(pr > 0) i = nxti;
		else if(pr < 0) j = nxtj;
		else i = nxti, j = nxtj; 
	}while((a[i] + b[j]) != out[0]);
	return out;
}

long double ang[2 * MAXN]; 
int cur_len = 0;
PT lower;
int low_idx = 0;  

long double get_ang(PT p){
	if(p.y == 0){
		if(p.x > 0) return 0;
		else return PI; 
	}
	else{
		if(p.x == 0) return PI / 2;
		else if(p.x > 0) return atan2(p.y * 1.0, p.x * 1.0);
		else{
			return (PI / 2) + atan2(-p.x * 1.0, p.y * 1.0); 
		}
	}
}

void process(vector< PT >& poly){
	int len = sz(poly);
	int idx = 0;
	for(int q = 0; q < len; ++q)
		if(compare(poly[q], poly[idx])) idx = q;
	lower = poly[idx];
	low_idx = idx; 
	cur_len = len - 1;
	for(int i = 1; i < len; ++i){
		int curidx = (i + idx) % len;	
		ang[i - 1] = get_ang(poly[curidx] - poly[idx]);
	}
}


ld area(PT p1, PT p2, PT p3){
	ld ret = 0;
	vector< PT > tmp;
	tmp.pb(p1); tmp.pb(p2); tmp.pb(p3);
	for(int i = 0; i < 3; ++i){
		int j = (i + 1) % 3;
		ret += (ld(tmp[i].x) * ld(tmp[j].y) - ld(tmp[i].y) * ld(tmp[j].x)); 
	}
	ret = abs(ret);
	return ret / 2;
}

bool triangle_inside(PT p1, PT p2, PT p){
	PT orig;
	orig.x = 0;
	orig.y = 0; 
	ld area_total = area(orig, p1, p2);
	ld false_area = area(orig, p1, p) + area(orig, p, p2) + area(p , p1, p2); 
	if(abs(area_total - false_area) < EPS) return true;
	else return false;
}

bool inside(PT p, vector< PT >& poly){
	p = p - lower;
	if(p.x == 0 && p.y == 0) return true;
	long double angulo = get_ang(p);
	if(angulo + EPS < ang[0]) return false;
	if(angulo > ang[cur_len - 1] + EPS) return false;
	int lo = -1, hi = cur_len - 1; 
	while(hi - lo > 1){
		int mid = (lo + hi) / 2;
		if(ang[mid] > (angulo + EPS)) hi = mid;
		else lo = mid;
	}
	PT P1 = poly[(low_idx + hi) % (cur_len + 1)] - lower;
	PT P2 = poly[(low_idx + hi + 1) % (cur_len + 1)] - lower;
	return triangle_inside(P1, P2, p);
}

int main(){
	vector< PT > poly1; poly1.clear();
	vector< PT > poly2; poly2.clear(); 
	vector< PT > poly3; poly3.clear(); 
	PT p; 
	ll x, y;
	int n1; scanf("%d", &n1);
	for(int i = 0; i < n1; ++i){
		scanf("%lld %lld", &x, &y); 
		p.x = x; p.y = y;
		poly1.pb(p); 
	} 
	int n2; scanf("%d", &n2);
	for(int i = 0; i < n2; ++i){
		scanf("%lld %lld", &x, &y); 
		p.x = x; p.y = y;
		poly2.pb(p); 
	}
	int n3; scanf("%d", &n3);
	for(int i = 0; i < n3; ++i){
		scanf("%lld %lld", &x, &y); 
		p.x = x; p.y = y;
		poly3.pb(p); 
	}
	vector< PT > poly12 = minkow_sum(poly1, poly2);
	vector< PT > poly123 = minkow_sum(poly12, poly3);
	int m; scanf("%d", &m);
	process(poly123); 
	for(int query = 0; query < m; ++query){
		scanf("%lld %lld", &x, &y);
		p.x = 3 * x; p.y = 3 * y;
		if(inside(p, poly123)) printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
} 
