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
#define itm3 snd.fst
#define itm4 snd.snd
#define mt(a,b,c) mp(mp(a,b),c)
#define mc(a, b, c, d) mp(mp(a, b), mp(c,d))


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

vector< pair< ii, ii > > ad[MAXN];
int aq[MAXN];
int books[MAXN];
int state[MAXN];
int dp[MAXN];
int grid[1002][1002];
int n, m;

void dfs(int u){
    for(int i = 0 ; i < int(ad[u].size()) ; ++i){
        pair< ii , ii > v = ad[u][i];
        int w = v.itm1;
        int r = v.itm3;
        int c = v.itm4;
        if(v.itm2 == 2){
            if(state[r] == 1){ // right order
                if(grid[r][c] == 1){
                    grid[r][c] = 0;
                    books[r] --;
                    dp[w] = dp[u] - 1;
                    dfs(w);
                    grid[r][c] = 1;
                    books[r] ++;
                }
                else{
                    dp[w] = dp[u]; // nothing happens
                    dfs(w);
                }
            }
            else{ // alternative order
                if(grid[r][c] == 1){ // nothing happens
                    dp[w] = dp[u];
                    dfs(w);
                }
                else{
                    grid[r][c] = 1;
                    books[r] ++;
                    dp[w] = dp[u] - 1;
                    dfs(w);
                    books[r] --;
                    grid[r][c] = 0;
                }
            }
        }
        else if(v.itm2 == 1){
                if(state[r] == 1){
                    if(grid[r][c] == 1){
                        dp[w] = dp[u];
                        dfs(w);
                    }
                    else{
                        grid[r][c] = 1;
                        books[r] ++;
                        dp[w] = dp[u] + 1;
                        dfs(w);
                        books[r] --;
                        grid[r][c] = 0;
                    }
                }
                else{
                    if(grid[r][c] == 1){
                        grid[r][c] = 0;
                        books[r] --;
                        dp[w] = dp[u] + 1;
                        dfs(w);
                        books[r] ++;
                        grid[r][c] = 1;
                    }
                    else{
                        dp[w] = dp[u];
                        dfs(w);
                    }
                }
        }
        else if(v.itm2 == 3){
           if(state[r] == 1){
                state[r] = 0;
                dp[w] = dp[u] + m - 2 * books[r];
                dfs(w);
                state[r] = 1;
           }
           else{
                state[r] = 1;
                dp[w] = dp[u] + 2 * books[r] - m;
                dfs(w);
                state[r] = 0;
           }
        }
    }
}


int main(){
    fast_io();
    int q; cin >> n >> m >> q;
    int op;
    int i, j, k;
    int cur = 0;
    for(int i = 0 ; i < MAXN ; ++i) state[i] = 1;
    for(int req = 1 ; req <= q ; ++req){
        cin >> op;
        if(op == 1){
            cin >> i >> j;
            --i, --j;
            ad[cur].pb(mc(req, 1, i , j));
            cur = req;
        }
        else if(op == 2){
            cin >> i >> j;
            --i, --j;
            ad[cur].pb(mc(req, 2, i, j));
            cur = req;
        }
        else if(op == 3){
            cin >> i;
            --i;
            ad[cur].pb(mc(req, 3, i, - 1));
            cur = req;
        }
        else{
            cin >> k;
            cur = aq[k];
        }
        aq[req] = cur;
    }
  
    dfs(0);
    for(int i = 1 ; i <= q ; ++i){
        cout << dp[aq[i]] << endl;
    }
    return 0;
}
