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


struct Ktype{
	int l, r;
	char lvl;
	vector< int > v;
	
	void clear(){
		l = 0, r = 0;
		lvl = 0;
		v.clear();
	}
};

struct node{
	int l, r;
	int tot;	
	
	void clear(){
		l = 0, r = 0;
		tot = 0;
	}
};

struct SegmentTree{
	node tree[4 * MAXN];	
	int n;	
	
	void init(int nodo, int a, int b){
		if(a == b){
			tree[nodo].l = 1;
			tree[nodo].r = 1;
			tree[nodo].tot = 1;
			return;
		}
		int mid = (a + b) / 2;
		init(2 * nodo, a, mid);
		init(2 * nodo + 1, mid + 1, b);
		tree[nodo].l = b - a + 1;
		tree[nodo].r = b - a + 1;
		tree[nodo].tot = b - a + 1;
	}
	
	void build(){
		init(1, 0, n - 1);
	}
	
	void update(int nodo, int a, int b, int id){
		if(a > id || id > b) return;
		if(a == b){
			tree[nodo].l = 0;
			tree[nodo].r = 0;
			tree[nodo].tot = 0;
			return;
		}
		int mid = (a + b) / 2;
		update(2 * nodo, a, mid, id);
		update(2 * nodo + 1, mid + 1, b, id);

		tree[nodo].l = tree[2 * nodo].l;
		if(tree[2 * nodo].tot == (mid - a + 1))
			tree[nodo].l = (mid - a + 1) + tree[2 * nodo + 1].l;

		tree[nodo].r = tree[2 * nodo + 1].r;
		if(tree[2 * nodo + 1].tot == (b - mid))
			tree[nodo].r = (b - mid) + tree[2 * nodo].r;
		
		int valueM = max(tree[nodo].l, tree[nodo].r);
		valueM = max(valueM, tree[2 * nodo].tot);
		valueM = max(valueM, tree[2 * nodo + 1].tot);
		valueM = max(valueM, tree[2 * nodo].r + tree[2 * nodo + 1].l);
		
		tree[nodo].tot = valueM;		
	}

	void upd(int id){
		update(1, 0, n - 1, id);
	}

	node get_query(int nodo, int a, int b, int le, int ri){
		node tmp;
		tmp.l = -1, tmp.r = -1, tmp.tot = -1;
		if(ri < a || le > b) return tmp;
		if(ri >= b && le <= a) return tree[nodo]; 
		int mid = (a + b) / 2;
		node q1 = get_query(2 * nodo, a, mid, le, ri);
		node q2 = get_query(2 * nodo + 1, mid + 1, b, le, ri);
		if(q1.l == -1 && q1.r == -1 && q1.tot == -1) return q2;
		if(q2.l == -1 && q2.r == -1 && q2.tot == -1) return q1;
		
		tmp.l = q1.l;
		if(q1.tot == (mid - a + 1))
			tmp.l = (mid - a + 1) + q2.l;
		
		tmp.r = q2.r;
		if(q2.tot == (b - mid))
			tmp.r = (b - mid) + q1.r;
	
		tmp.tot = max(q1.tot, q2.tot);
		tmp.tot = max(tmp.tot, tmp.l);
		tmp.tot = max(tmp.tot, tmp.r);
		tmp.tot = max(tmp.tot, q1.r + q2.l);
	
		return tmp;		
	}

	node get(int a, int b){
		return get_query(1, 0, n - 1, a, b);
	}

};

vector< int > valores[MAXN]; 
int answer[MAXN];
int h[MAXN];
int l[MAXN];
int r[MAXN];
int w[MAXN];
int value[MAXN];

int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &h[i]);
	int m; scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d", &l[i], &r[i], &w[i]);
		--l[i], --r[i];
	}
	
	queue< Ktype > q;
	Ktype t, t1, t2;
	t.clear(); t1.clear(); t2.clear();
	t.l = 0;
	t.r = 1e9 + 5;
	t.lvl = 0;
	for(int i = 0; i < m; ++i) (t.v).pb(i);
	char cur_level = 0;
	
	q.push(t);
	t.clear();

	SegmentTree st;
	st.n = n;
	st.build();
	int idx = -1;
	
	int len = 0;
	
	set< int > sw;
	for(int i = 0; i < n; ++i) sw.insert(h[i]);

	map< int, int > mapa;
	for(auto it = sw.begin(); it != sw.end(); ++it){
		mapa[*it] = len;
		value[len++] = *it;
	}

	for(int i = 0; i < n; ++i){
		int ind = mapa[h[i]]; 
		valores[ind].pb(i); 
	}
	
	while(!q.empty()){
		t = q.front();
		q.pop();
		if(t.lvl != cur_level){
			st.build();	
			idx = -1;
			cur_level = t.lvl; 
		}		
		int middle = (t.l + t.r) / 2;

		for(int i = idx + 1; i < len; ++i){
			if(value[i] >= middle) break;
			else{
				for(int j = 0; j < sz(valores[i]); ++j){
					st.upd(valores[i][j]); 
				}
				idx = i;
			}
		}
		 
		if(t.l + 1 == t.r){
			for(int i = 0; i < sz(t.v); ++i){
				int id = (t.v)[i];
				node ans = st.get(l[id], r[id]);
				if(ans.tot >= w[id]) answer[id] = t.l;
				else answer[id] = -1;
			}
			continue;
		}
		for(int i = 0; i < sz(t.v); ++i){
			int id = (t.v)[i];
			node ans = st.get(l[id], r[id]);
			if(ans.tot >= w[id]) (t2.v).pb(id);
			else (t1.v).pb(id); 
		}
		t1.l = t.l;
		t1.r = middle;
		t2.l = middle;
		t2.r = t.r;
		t1.lvl = t.lvl + 1;
		t2.lvl = t.lvl + 1;
		if(!(t1.v).empty()) q.push(t1);
		if(!(t2.v).empty()) q.push(t2);
		t.clear();
		t1.clear();
		t2.clear();
	}

	for(int i = 0; i < m; ++i) 
		printf("%d\n", answer[i]);

	return 0; 
}
 
