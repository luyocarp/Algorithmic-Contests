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
const ll LINF = 1e16 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


vector< char > av[MN + MAXN];
tri event[MN + MAXN];
vector< char > fre[MN + MAXN];
bool used[101];
int ans[MAXN];


int main(){
	
	int n, q; 
	scanf("%d %d", &n, &q);
	
	int t,k , d;
	for(int i = 0; i < MAXN + MN; ++i){
		event[i] = mt(-1,-1,-1);
	}
	for(int i = 0; i < q; ++i){
		scanf("%d %d %d", &t, &k, &d);
		event[t] = mt(k, d, i);
	}

	for(int t = 1; t <= MN + 4000; ++t){
		for(int i = 0; i < fre[t].size(); ++i){
			int x = fre[t][i];
			used[x] = 0;
		}
		for(int i = 1; i <= n; ++i){
			if(!used[i]) av[t].pb(i);
		}
		
		if(event[t].itm1 == -1) continue;
		int k1 = event[t].itm1;
		int d1 = event[t].itm2;
		int id = event[t].itm3;
		if(int(av[t].size()) < k1){
			ans[id] = -1;
		}		
		else{
			int sum = 0;
			for(int i = 0; i < k1; ++i){
				sum += av[t][i];
				fre[t + d1].pb(av[t][i]);
				used[av[t][i]] = 1;	
			}
			ans[id] = sum;			
		}
	}

	for(int i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
} 
