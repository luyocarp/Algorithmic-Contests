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
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


ll fenwick[MN + 5];

void update(int id, ll val){
	while (id <= MN + 1){
		fenwick[id] += val;
		id += (id & -id);
	}
}

ll getVal(int id){
	ll sum = 0;
	while (id > 0){
		sum += fenwick[id];
		id -= (id & -id);
	}
	return sum;
}

ll recover(int le, int ri){
	if(le > ri) return 0;
	if(ri == 0) return 0;
	if(le == 0) return getVal(ri);
	return getVal(ri) - getVal(le - 1);
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	ll ret1, ret2;
	ll ans = 1;
	ll rec = 0;
	k = min(k, n - k);
	for(int i = 0; i < n; ++i){
		ret1 = ll(i) * k;
		ret1 %= n;
		ret2 = (ret1 + k) % n;
		++ret1, ++ret2;
		rec = 0;
		if(ret1 < ret2){
			rec = recover(ret1 + 1, ret2 - 1);
		}
		else{
			rec = recover(ret1 + 1, n) + recover(1, ret2 - 1);
		}
		ans += rec + 1;
		printf("%lld ", ans);
		update(ret1, 1); 
		update(ret2, 1);
	}
	printf("\n");
	return 0;
} 
