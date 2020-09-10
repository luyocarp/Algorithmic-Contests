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

map< string , int > mapa;
map< int, string > mr;
set< string > mark;
set< string > :: iterator it;
int cnt = 0;
int control[MAXN];
int used[MAXN];
vector< int > ad[MAXN];

int get(string s){
    if(mapa.count(s)) return mapa[s];
    mapa[s] = cnt;
    mr[cnt] = s;
    ++cnt;
    return cnt - 1;
}

void dfs(int u){
    used[u] = 1;
    for(int i = 0 ; i < ad[u].size() ; ++i){
        int v = ad[u][i];
        if(!used[v]) dfs(v);
    }
}

int main(){
    fast_io();
    int T; cin >> T;
    while(T--){
        int u, v, m; cin >> u >> v >> m;
        int tot = 0;
        string s;
        mark.clear();
        cnt = 0;
        mapa.clear();
        mr.clear();
        for(int i = 0 ; i < u ; ++i){
            cin >> s;
            control[tot++] = get(s);
        }

        for(int i = 0 ; i < v ; ++i){
            cin >> s;
            mark.insert(s);
        }
        string s1, s2;
        for(int i = 0 ; i < 1e4 + 5 ; ++i) ad[i].clear();
        for(int i = 0 ; i < m ; ++i){
            cin >> s1 >> s2;
            int id1 = get(s1);
            int id2 = get(s2);
            ad[id1].pb(id2);
        }

        for(int i = 0 ; i < cnt ; ++i) used[i] = 0;
        for(int i = 0 ; i < tot ; ++i){
            if(!used[control[i]]) dfs(control[i]);
        }
        set< string > ans;
        ans.clear();
        for(int i = 0 ; i < cnt ; ++i){
            if(used[i] && mark.count(mr[i])) ans.insert(mr[i]);
        }

        for(it = ans.begin() ; it != ans.end() ; ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
