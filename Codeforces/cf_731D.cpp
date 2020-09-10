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

vector< int > v[5 * MAXN];
ii inter[5 * MAXN];
bool sol[MN];
map< int, vector< int > > entrada;
map< int, vector< int > > salida;
set< int > sw;

int main(){
    fast_io();
    int n, c; cin >> n >> c;
    int x;
    int t;
    for(int i = 0 ; i < n ; ++i){
        cin >> x;
        for(int j = 0 ; j < x ; ++j){
            cin >> t;
            --t;
            v[i].pb(t);
        }
    }
    int wrong = 0;
    int cnt = 0;
    for(int i = 0 ; i < n - 1; ++i){
        bool ok = 0;
        for(int j = 0 ; j < int(v[i].size()) && j < int(v[i + 1].size()) ; ++j){
            if(v[i][j] != v[i+1][j]){
                ok = 1;
                inter[cnt++] = mp(v[i][j], v[i+1][j]);
                break;
            }
        }
        if(!ok){
            if(v[i+1].size() < v[i].size()){
                wrong = 1;
                break;
            }
        }
    }

    if(wrong){
        cout << "-1" << endl;
    }
    else{
        int menor = 0, mayor = c - 1;
        for(int i = 0 ; i < cnt ; ++i){
            int x1 = inter[i].fst, x2 = inter[i].snd;
            if(x1 > x2){
                menor = max(menor, c - x1);
                mayor = min(mayor, c - x2 - 1);
            }
        }
        debug(menor); debug(mayor);
        for(int i = menor ; i <= mayor ; ++i) sol[i] = 1;
        for(int i = 0 ; i < cnt ; ++i){
            int x1 = inter[i].fst, x2 = inter[i].snd;
            if(x1 < x2){
                entrada[c - x2].pb(i);
                salida[c - x1 - 1].pb(i);
            }
        }
        for(int i = 0 ; i < c ; ++i){
            if(!entrada[i].empty()){
                for(int j = 0 ; j < int(entrada[i].size()) ; ++j){
                    sw.insert(entrada[i][j]);
                }
            }
            if(!sw.empty()) sol[i] = 0;
            if(!salida[i].empty()){
                for(int j = 0 ; j < int(salida[i].size()) ; ++j){
                    sw.erase(salida[i][j]);
                }
            }
        }
        int ans = -1;
        for(int i = menor ; i <= mayor ; ++i){
            if(sol[i]) ans = i;
        }
        cout << ans << endl;

    }
    return 0;
}
