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

vector< tri > ad[MAXN];
deque< int > dq;
ll rem[MAXN];

void dfs(int u){
    for(int i = 0 ; i < int(ad[u].size()) ; ++i){
        tri v = ad[u][i];
        int option = v.itm1;
        int w = v.itm2;
        int cop = v.itm3;
        if(option == 1){
            dq.push_front(cop);
            dfs(w);
            dq.pop_front();
        }
        else{
            int tmp = dq.back();
            dq.pop_back();
            rem[w] = tmp;
            dfs(w);
            dq.push_back(tmp);
        }
    }
}

int main(){
    fast_io();
    int Q; cin >> Q;
    char op;
    int version;
    int x;
    for(int req = 1 ; req <= Q ; ++req){
        cin >> op;
        if(op == 'E'){
            cin >> version >> x;
            ad[version].pb(mt(1, req, x));
        }
        else{
            cin >> version;
            ad[version].pb(mt(-1, req, -1));
        }
    }

    for(int i = 0 ; i <= Q ; ++i) rem[i] = LINF;
    dfs(0);
    for(int i = 0 ; i <= Q ; ++i){
        if(rem[i] != LINF) cout << rem[i] << endl;
    }

    return 0;
}
