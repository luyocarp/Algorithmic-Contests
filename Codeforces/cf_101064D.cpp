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
ll n, k;

ll ok(ll mid){
    ll ans = 0;
    ll r = n - 1;
    for(int l = 0 ; l < n ; ++l){
       if(l >= r) break;
       while(r > l && xx[l] + xx[r] > mid) --r;
       ans += (r - l);
    }
    return ans;
}

int main(){
    fast_io();
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i){
        cin >> xx[i];
    }
    sort(xx, xx + n);
    ll lo = 0, hi = LINF;

    while(lo < hi){
        ll mid = (lo + hi)/2;
        if(ok(mid) < k) lo = mid + 1;
        else hi = mid;
    }

    cout << lo << endl;
    return 0;
}
