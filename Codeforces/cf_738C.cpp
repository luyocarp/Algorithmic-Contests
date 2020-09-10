#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cout << #x << ": " << x << endl;
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

ll c[2 * MAXN];
ll v[2 * MAXN];
ll g[2 * MAXN];
ll difg[2 * MAXN];
ll n, k, s, t;
ll parc[2 * MAXN];
ll u;

ll get(int pos){
    if(pos < 0) return 0;
    return parc[pos];
}

ll go(int i){
    if(u > v[i]) return -1;
    int pos = lower_bound(difg, difg + k + 1, v[i]) - difg;
    ll tt = 3 * s - v[i] * (k - pos + 1) - get(pos - 1);
    if(tt <= t) return c[i];
    else return -1;
}


int main(){
    fast_io();
    cin >> n >> k >> s >> t;
    for(int i = 0; i < n; ++i){
        cin >> c[i] >> v[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> g[i + 1];
    }
    sort(g + 1, g + k + 1);
    g[0] = 0; g[k + 1] = s;
    u = 0;
    for(int i = 0; i <= k; ++i){
        difg[i] = g[i + 1] - g[i];
        u = max(u, difg[i]);
        difg[i] *= 2;
    }
    sort(difg, difg + k + 1);
    parc[0] = difg[0];
    for(int i = 1; i <= k ; ++i)
        parc[i] = parc[i - 1] + difg[i];

    ll costo = LINF;
    for(int i = 0; i < n; ++i){
        ll ret = go(i);
        if(ret != -1){
            if(costo > ret){
                costo = ret;
            }
        }
    }

    if(costo == LINF) cout << "-1" << endl;
    else cout << costo << endl;
    return 0;
}
