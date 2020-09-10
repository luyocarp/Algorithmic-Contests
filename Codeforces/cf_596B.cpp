#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
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
const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7; 
const int MAXN = 2e5 + 6;
const int MN = 1e6 + 2;


int n;
ll fenwick_add[MAXN + 1] , fenwick_mul[MAXN +1] ; 

void internal_update(int idx, ll mul, ll add){
	while( idx <= n ){
		fenwick_mul[idx] += mul; 
		fenwick_add[idx] += add; 
		idx |= (idx + 1); 
	}
}

void update_interval(int le, int ri, ll val){
	internal_update(le,val, -val*(le-1));
	internal_update(ri,-val, val*ri); 
}	

ll Recover_interval(int idx){
	ll mul = 0 , add = 0; 
	int start = idx; 
	while(idx >= 0){
		mul += fenwick_mul[idx]; 
		add += fenwick_add[idx];
		idx = (idx & (idx + 1) ) - 1;
	} 
	return mul*start + add; 
}

ll get(int idx){
  if(idx == 0) return 0;
  return Recover_interval(idx) - Recover_interval(idx - 1);
}

int a[MN]; 

int main(){
  fast_io();
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    update_interval(i + 1, i + 1, a[i]);   
  }
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll cur = get(i + 1);
    ans += abs(cur);
    update_interval(i + 2, n, -cur);
  }
  
  cout << ans << endl;
  return 0; 
}
