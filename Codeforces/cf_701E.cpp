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
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;

vector< int > ad[2*MAXN];
bool used[2*MAXN];
bool mark[2*MAXN];
int dp[2*MAXN];

void dfs(int u, int padre){
    used[u] = 1;
    int len = int(ad[u].size());
    for(int i = 0 ; i < len ; ++i){
        int v = ad[u][i];
        if(v == padre) continue;
        if(!used[v]) dfs(v,u);
        dp[u] += dp[v];
    }
    if(mark[u]) ++dp[u];
}

int main(){
    fast_io();
    int n, k; cin >> n >> k;
    int x, y;
    for(int i = 0 ; i < 2 * k ; ++i){
        cin >> x;
        --x;
        mark[x] = 1;
    }
    for(int i = 1 ; i < n ; ++i){
        cin >> x >> y;
        --x,--y;
        ad[x].pb(y);
        ad[y].pb(x);
    }

    ll sum = 0;
    dfs(0,0);
    for(int i = 0 ; i < n ; ++i) sum += min(dp[i], 2*k - dp[i]);
    cout << sum << endl;
    return 0;
}
