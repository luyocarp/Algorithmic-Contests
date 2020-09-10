#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
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
typedef pair<ii, int> tri;
typedef pair<int,bool> ib;
typedef unsigned int uint;


const double PI = acos(-1);
//const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7; 
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;

#define REMOVE_REDUNDANT

typedef ll T;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) == 0 && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}

vector< PT > puntos;
int len;

ii get(int i){
	int r = i + 2;
	ll maximo = - 1; 
	int v1, v2;
	for(int l = i + 1; l < len - 1 ; ++l){
		r = max(l + 1, r);
		if(r >= len) break;
		if(abs(area2(puntos[i], puntos[l], puntos[r])) > maximo){
			maximo = abs(area2(puntos[i], puntos[l], puntos[r]));
			v1 = l , v2 = r;
		}
		while(r < len - 1 && abs(area2(puntos[i], puntos[l], puntos[r])) < abs(area2(puntos[i], puntos[l], puntos[r + 1]))) ++r;
		if(abs(area2(puntos[i], puntos[l], puntos[r])) > maximo){
			maximo = abs(area2(puntos[i], puntos[l], puntos[r]));
			v1 = l , v2 = r;
		}
		continue;
	}
	return mp(v1, v2);
}

int main(){
	int n; scanf("%d",&n);
	ll S; scanf("%I64d",&S);
	ll xx, yy;
	PT pp;
	for(int i = 0 ; i < n ; ++i){
		scanf("%I64d %I64d", &xx, &yy);
		pp.x = xx, pp.y = yy;
		puntos.pb(pp);
	}

	ConvexHull(puntos);
	ll x, y, z;
	len = puntos.size();
	#ifdef DEBUG
	cout << "ALL POINTS" << endl;
	for(int i = 0 ; i < len ; ++i){
		cout << puntos[i].x <<  " " << puntos[i].y << endl;
	}
	cout << "--------" << endl;
	#endif
	int v1, v2, v3;
	ll maximo = -1;
	for(int i = 0 ; i < len - 2; ++i){
			ii x = get(i);
			if(abs(area2(puntos[i], puntos[x.fst], puntos[x.snd])) > maximo){
				maximo = abs(area2(puntos[i], puntos[x.fst], puntos[x.snd]));
				v1 = i, v2 = x.fst, v3 = x.snd;
			}
	} 
	
	PT p1, p2, p3;
	p1.x = puntos[v2].x + puntos[v3].x - puntos[v1].x;
	p1.y = puntos[v2].y + puntos[v3].y - puntos[v1].y;
	p2.x = puntos[v1].x + puntos[v3].x - puntos[v2].x;
	p2.y = puntos[v1].y + puntos[v3].y - puntos[v2].y;
	p3.x = puntos[v1].x + puntos[v2].x - puntos[v3].x;
	p3.y = puntos[v1].y + puntos[v2].y - puntos[v3].y;

	printf("%I64d %I64d\n",p1.x, p1.y);
	printf("%I64d %I64d\n",p2.x, p2.y);
	printf("%I64d %I64d\n",p3.x, p3.y);

	return 0;
}
