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

ll xx[MAXN];

ll mintri(ll a, ll b, ll c){
    return min(a, min(b, c));
}

int main(){
    fast_io();
    int n; cin >> n;
    ll a; cin >> a;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; ++i){
        cin >> xx[i];
    }
    sort(xx, xx + n);
    
    ll ans = LINF;
    ll ret = 0;
    if(a <= xx[0]){
        ret += abs(a - xx[0]);
        for(int i = 0 ; i < n - 2 ; ++i){
            ret += abs(xx[i] - xx[i + 1]);
        }
        cout << ret << endl;
        return 0;
    }
    if(a >= xx[n - 1]){
        ret += abs(xx[n - 1] - a);
        for(int i = 1 ; i < n - 1; ++i){
            ret += abs(xx[i] - xx[i + 1]);
        }
        cout << ret << endl;
        return 0;
    }
     int pos = lower_bound(xx, xx + n, a) - xx;
    --pos;
    ll ret10, ret11, ret20, ret21;
    ret10 = abs(xx[pos] - a) + abs(xx[pos] - xx[0]);
    if(pos >= 1) ret11 = abs(xx[pos] - a) + abs(xx[pos] - xx[1]);
    else ret11 = LINF;

    ret20 = abs(xx[pos + 1] - a) + abs(xx[n - 1] - xx[pos + 1]);
    if(pos + 1 < (n - 1)) ret21 = abs(xx[pos + 1] - a) + abs(xx[n - 2] - xx[pos + 1]);
    else ret21 = LINF;

    if(ret11 != LINF && ret21 != LINF){
        ans = mintri(ans, 2*ret10 + ret21, ret10 + 2*ret21);
        ans = mintri(ans, 2*ret20 + ret11, ret20 + 2*ret11);
    }
    else if(ret11 != LINF){
        ans = mintri(ans, 2*ret20 + ret11, ret20 + 2*ret11);
        ans = min(ans, ret10);

    }
    else if(ret21 != LINF){
        ans = mintri(ans, 2*ret10 + ret21, ret10 + 2*ret21);
        ans = min(ans, ret20);
    }
    else{
        ans = min(ans, ret10);
        ans = min(ans, ret20);
    }
    cout << ans << endl;
    return 0;
}
