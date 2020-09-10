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

int last;
vector< ll > sol;
vector< ll > v[200];
int len[200];
int m;
int k;

void solve(int u){
    if(u == m) return;
    if(u == 0){
        for(int i = 0 ; i < len[0] ; ++i) sol.pb(v[0][i]);
        sort(all(sol));
        while(sol.size() > k){
            sol.erase(sol.end() - 1);
        }
        solve(u + 1);
        return;
    }
    vector< ll > tmp;
    for(int i = 0 ; i < sol.size() ; ++i){
        for(int j = 0 ; j < len[u] ; ++j){
            tmp.pb(sol[i] + v[u][j]);
        }
    }
    sort(all(tmp));
    while(tmp.size() > k){
        tmp.erase(tmp.end() - 1);
    }

    sol.clear();
    for(int i = 0 ; i < tmp.size() ; ++i) sol.pb(tmp[i]);
    solve(u + 1);

}

int main(){
    fast_io();
    int T; cin >> T;
    while(T--){
        cin >> m >> k;
        for(int i = 0 ; i < m ; ++i){
            cin >> len[i];
            v[i].clear();
            v[i].resize(len[i]);
            for(int j = 0 ; j < len[i] ; ++j){
                cin >> v[i][j];
            }
            sort(all(v[i]));
        }
        sol.clear();
        solve(0);
        for(int i = 0 ; i < k ; ++i){
            cout << sol[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
