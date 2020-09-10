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
const int MAXN = 3300000;
const int MN = 1e6 + 2;

int cont = 0;
int Next[2][MAXN];
int hijos[2 * MAXN];

void _insert(ll N, int val){
    int v = 0;
    int tmp;
    for(int i = 33 ; i >=0 ; --i){
        tmp = (N & (1LL << i)) ? 1 : 0;
        if(!Next[tmp][v]) Next[tmp][v] = ++cont;
        v = Next[tmp][v];
        hijos[v] += val;
    }
}

ll query(ll N){
    int v = 0;
    ll ans = 0;
    int tmp;
    for(int i = 33 ; i >= 0 ; --i){
        tmp = (N & (1LL << i)) ? 1 : 0;
        if(Next[1 - tmp][v] && hijos[Next[1 - tmp][v]] > 0){
            ans += (1LL << i);
            v = Next[1 - tmp][v];
        }
        else{
            v = Next[tmp][v];
        }
    }
    return ans;
}

int main(){
   fast_io();
   int q; cin >> q;
   char c; ll x;
   cont = 0;
   for(int i = 0 ; i < MAXN ; ++i) Next[0][i] = Next[1][i] = 0;
   for(int i = 0 ; i < 2*MAXN ; ++i) hijos[i] = 0;
   _insert(0,1);
   for(int i = 0 ; i < q ; ++i){
    cin >> c >> x;
    if(c == '+'){
        _insert(x, 1);
    }
    else if(c == '-'){
        _insert(x, -1);
    }
    else{
        cout << query(x) << endl;
    }
   }
    return 0;
}
