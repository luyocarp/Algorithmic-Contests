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


int dirx[] = { 1, -1 , 0 , 0};
int diry[] = { 0, 0 , -1, 1};
int cont = 0 ;
vector< int > comp[2800];
int mark[2800];
vector< ii > falta;
string grid[55];
int used[2800];
int n, m;

void dfs(int x){
    int r = x / 52;
    int c = x % 52;
    used[x] = 1;
    comp[cont].pb(x);
    mark[x] = cont;
    for(int d = 0 ; d < 4 ; ++d){
        int rr = r + dirx[d];
        int cc = c + diry[d];
        if(rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
        if(!used[52 * rr + cc] && grid[rr][cc] == '.'){
            dfs(52 * rr + cc);
        }
    }
}

int main(){
    fast_io();
    int  k; cin >> n >> m >> k;
    for(int i = 0 ; i < n ; ++i) cin >> grid[i];
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            if(!used[i * 52 + j] && grid[i][j] == '.'){
                dfs(52 * i + j);
                ++cont;
            }
        }
    }

    for(int i = 0 ; i < m ; ++i){
        if(grid[0][i] == '.') comp[mark[i]].clear();
        if(grid[n - 1][i] == '.') comp[mark[52 * (n - 1) + i]].clear();
    }

    for(int i = 0 ; i < n ; ++i){
        if(grid[i][0] == '.') comp[mark[52 * i]].clear();
        if(grid[i][m - 1] == '.') comp[mark[52 * i + (m - 1)]].clear();
    }

    for(int i = 0 ; i < 2800 ; ++i){
        if(!comp[i].empty()){
            falta.pb(mp(comp[i].size(), i));
        }
    }

    sort(all(falta));
    int len = int(falta.size());
    int ans = 0;
    for(int i = 0 ; i < len - k ; ++i){
        ans += falta[i].fst;
        for(int j = 0 ; j < int(falta[i].fst) ; ++j){
            int casilla = comp[falta[i].snd][j];
            grid[casilla / 52][casilla % 52] = '*';
        }
    }

    cout << ans << endl;
    for(int i = 0 ; i < n ; ++i){
        cout << grid[i] << endl;
    }

    return 0;
}
