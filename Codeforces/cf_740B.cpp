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


ll a[105];
ll l[105];
ll r[105];
ll dp[105];

ll ret(int u){
    ll s = 0;
    for(int i = l[u] ; i <= int(r[u]) ; ++i){
        s += a[i];
    }
    return s;
}

int main(){
    int n,m; cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i =  1; i  <= m ; ++i) cin >> l[i] >> r[i];
    dp[0] = 0;
    for(int i = 1 ; i <= m ; ++i){
        dp[i] = max(dp[i - 1], dp[i - 1] + ret(i));
    }
    cout << dp[m] << endl;
    return 0;
} 
