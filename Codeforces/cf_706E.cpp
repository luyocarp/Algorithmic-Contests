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

int n, m;
int vv[1010][1010];
int d[1100000];
int r[1100000];


int get(int u, int v){
    return u * (m + 2) + v;
}

ii get_rev(int x){
    int r = x / (m + 2);
    int c = x % (m + 2);
    return mp(r, c);
}

int ffind(int x, int y){
    int beg = 0;
    for(int i = 0 ; i < x ; ++i) beg = d[beg];
    for(int i = 0 ; i < y ; ++i) beg = r[beg];
    return beg;
}


int main(){
    fast_io();
    int q; cin >> n >> m >> q;
    int aa, bb, cc, dd, h, w;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ;  ++j){
            cin >> vv[i][j];
        }
    }
    for(int i = 0; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            d[get(i,j)] = get(i + 1, j);
            r[get(i,j)] = get(i, j + 1);
        }
    }

    for(int i = 0 ; i < q ; ++i){
        cin >> aa >> bb >> cc >> dd >> h >> w;
        int _1 = ffind(aa - 1, bb - 1);
        int _2 = ffind(cc - 1, dd - 1);

        int _ur1 = _1;
        int _ur2 = _2;

        for(int rep = 0 ; rep < w ; ++rep){
            _ur1 = r[_ur1];
            _ur2 = r[_ur2];
            swap(d[_ur1], d[_ur2]);
        }

        int _dl1 = _1;
        int _dl2 = _2;
        for(int rep = 0 ; rep < h ; ++rep){
            _dl1 = d[_dl1];
            _dl2 = d[_dl2];
            swap(r[_dl1], r[_dl2]);
        }

        for(int rep = 0 ; rep < h ; ++rep){
            _ur1 = d[_ur1];
            _ur2 = d[_ur2];
            swap(r[_ur1], r[_ur2]);
        }

        for(int rep = 0 ; rep < w ; ++rep){
            _dl1 = r[_dl1];
            _dl2 = r[_dl2];
            swap(d[_dl1], d[_dl2]);
        }
    }

    int cur = 0;
    int _;
    for(int i = 0 ; i < n ; ++i){
        cur = d[cur];
        _ = cur;
        for(int j = 0 ; j < m ; ++j){
            _ = r[_];
            ii _t = get_rev(_);
            cout << vv[_t.fst][_t.snd] << " ";
        }
        cout << endl;
    }

    return 0;
}
