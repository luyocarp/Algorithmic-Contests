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
const int MAXN = 2e5 + 5;
const int MN = 1e6 + 2;
const int LOGN = 21;

ll a[MAXN];
vector< int > ad[MAXN];
int parent[MAXN][21];
ll dist[MAXN][21];
ll ans[MAXN];
ll tmp[MAXN];
bool used[MAXN];
int n;

void dfs(int u){
    used[u] = 1;
    for(int i = 0 ; i < int(ad[u].size()) ; ++i){
        int v = ad[u][i];
        if(v == parent[u][0]) continue;
        if(!used[v]) dfs(v);
        ans[u] += (ans[v] + tmp[v]);
    }
}


void do_p(){
    
    for(int j = 1 ; j < LOGN ; ++j){
        for(int i = 0; i <= n ; ++i){
            parent[i][j] = parent[parent[i][j-1]][j-1];
            dist[i][j] = dist[i][j - 1] + dist[parent[i][j-1]][j-1];
        }
    }
}


int get(int i){
    int u = i;
    for(int pr = 20 ; pr >= 0; --pr){
        if(dist[u][pr] <= a[i]){
            a[i] -= dist[u][pr];
            u = parent[u][pr];
        }
    }
    return u;
}

int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i) scanf("%I64d", &a[i]);
    int p;
    ll w;
    parent[1][0] = 1;
    dist[1][0] = 0;
    for(int i = 1; i <= n - 1; ++i){
        scanf("%d %I64d", &p, &w);
        ad[p].pb(i + 1);
        parent[i + 1][0] = p;
        dist[i + 1][0] = w;
    }

    do_p();
   
    for(int i = 1 ; i <= n ; ++i){
        int tt = get(i);
        tmp[tt] -= 1;
        tmp[i] += 1;
    }

    dfs(1);

    for(int i = 1 ; i <= n ; ++i) printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
} 
