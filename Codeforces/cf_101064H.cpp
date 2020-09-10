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
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int xx[20];
int yy[20];
int r1[20];
int r2[20];
string sx[1 << 17];
string  sy[1 << 17];
map< string ,int > orden;
bool primo[MAXN];
int prime[MAXN];
vector< ii > factx[20];
vector< ii > facty[20];
map< int, int > :: iterator it;

int main(){
    fast_io();
    int n, m; cin >> n >> m;
    int cntp = 0;
    for(int i = 2 ; i <= 1e5 ; ++i){
        if(!primo[i]){
            for(int j = 2 * i ; j <= 1e5 ; j += i)
                primo[j] = 1;
        }
    }
    for(int i = 2 ; i < 1e5 ; ++i) if(!primo[i]) prime[cntp++] = i;

    for(int i = 0 ; i < n ; ++i) cin >> xx[i];
    sort(xx, xx + n);


    for(int i = 0 ; i < m ; ++i) cin >> yy[i];
    sort(yy, yy + m);

    if(xx[0] == 1 && yy[0] == 1){
        cout << "Y" << endl;
        cout << "1 1" << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    int _n = 0, _m = 0;
    for(int i = 0 ; i < n ; ++i)
        if(xx[i] > 1) r1[_n++] = xx[i];

    for(int i = 0 ; i < m ; ++i)
        if(yy[i] > 1) r2[_m++] = yy[i];
    n = _n, m = _m;
    for(int i = 0 ; i < n ; ++i) xx[i] = r1[i];
    for(int i = 0 ; i < m ; ++i) yy[i] = r2[i];


    for(int i = 0 ; i < n ; ++i){
        for(int s = 0; s < cntp ; ++s){
            if(prime[s] * prime[s] > xx[i]) break;
            if(xx[i] % prime[s] == 0){
                int rr = 0;
                while(xx[i] % prime[s] == 0){
                    xx[i] /= prime[s];
                    ++rr;
                }
                factx[i].pb(mp(prime[s], rr));
            }
        }
        if(xx[i] > 1) factx[i].pb(mp(xx[i], 1));
    }


    for(int i = 0 ; i < m ; ++i){
        for(int s = 0 ; s < cntp ; ++s){
            if(prime[s] * prime[s] > yy[i]) break;
            if(yy[i] % prime[s] == 0){
                int rr = 0;
                while(yy[i] % prime[s] == 0){
                    ++rr;
                    yy[i] /= prime[s];
                }
                facty[i].pb(mp(prime[s], rr));
            }
        }
        if(yy[i] > 1) facty[i].pb(mp(yy[i], 1));
    }

    map< int, int > mapa;
    vector< char > tmp;
    for(int i = 1 ; i < (1 << n) ; ++i){
        mapa.clear();
        for(int j = 0 ; j < n ; ++j){
            if(i & (1 << j)){
                for(int u = 0 ; u < int(factx[j].size()) ; ++u){
                    mapa[factx[j][u].fst] += factx[j][u].snd;
                }
            }
        }
        sx[i - 1] = "";
        for(it = mapa.begin() ; it != mapa.end() ; ++it){
            int tt = it->fst;
            tmp.clear();
            while(tt != 0){
                tmp.pb(tt % 10 + '0');
                tt /= 10;
            }
            for(int d = int(tmp.size()) - 1; d >= 0 ; --d)
                sx[i - 1].pb(tmp[d]);
            tmp.clear();
            sx[i - 1].pb('_');
            tt = it->snd;
            while(tt != 0){
                tmp.pb(tt % 10 + '0');
                tt /= 10;
            }
            for(int d = int(tmp.size()) - 1; d >= 0 ; --d)
                sx[i - 1].pb(tmp[d]);
                sx[i - 1].pb('_');
        }
    }

     for(int i = 1 ; i < (1 << m) ; ++i){
        mapa.clear();
        for(int j = 0 ; j < m ; ++j){
            if(i & (1 << j)){
                for(int u = 0 ; u < int(facty[j].size()) ; ++u){
                    mapa[facty[j][u].fst] += facty[j][u].snd;
                }
            }
        }
        sy[i - 1] = "";
        for(it = mapa.begin() ; it != mapa.end() ; ++it){

            int tt = it->fst;
            tmp.clear();
            while(tt != 0){
                tmp.pb(tt % 10 + '0');
                tt /= 10;
            }
            for(int d = int(tmp.size()) - 1; d >= 0 ; --d)
                sy[i - 1].pb(tmp[d]);
            tmp.clear();
            sy[i - 1].pb('_');
            tt = it->snd;
            while(tt != 0){
                tmp.pb(tt % 10 + '0');
                tt /= 10;
            }
            for(int d = int(tmp.size()) - 1; d >= 0 ; --d)
                sy[i - 1].pb(tmp[d]);
                sy[i - 1].pb('_');
        }
        orden[sy[i - 1]] = i - 1;
    }
    sort(sy, sy + (1 << m) - 1);

    bool ok = 0;
    for(int i = 0 ; i < (1 << n) - 1 ; ++i){
        int pos = lower_bound(sy, sy + (1 << m) - 1, sx[i]) - sy;
        if(pos < 0 || pos >= ((1 << m) - 1))continue;
        if(sy[pos] == sx[i]){
            int right = orden[sy[pos]];
            cout << "Y" << endl;
            cout << ones(i + 1) << " " << ones(right + 1) << endl;
            for(int u = 0 ; u < n ; ++u){
                if((i + 1) & (1 << u)) cout << r1[u] << " ";
            }
            cout << endl;
            for(int u = 0 ; u < m ; ++u){
                if((right + 1) & (1 << u)) cout << r2[u] << " ";
            }
            return 0;
        }
    }
    cout << "N" << endl;

    return 0;
}
