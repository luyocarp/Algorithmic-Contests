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


int cuenta[2002];
vector< int > tt;
vector< int > ad[2002];
int xx[2002];
int n, m;
int cont = 0;

bool ok(int mid){
    ll ans = 0;
    for(int i = 1 ; i <= m ; ++i){
        if(cuenta[i] < mid){
            ans += mid - cuenta[i];
        }
    }

    ll av = cont;
    for(int i = 1 ; i <= m ; ++i){
        if(cuenta[i] > mid){
            av += cuenta[i] - mid;
        }
    }

    if(ans <= av) return 1;
    else return 0;
}

int main(){
    fast_io();
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        cin >> xx[i];
        if(xx[i] > m){
            tt.pb(i);
            ++cont;
        }
        else{
            ad[xx[i]].pb(i);
            cuenta[xx[i]] ++;
        }
    }

		int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1)/2;
        if(ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    int start = 0;
    for(int i = 1 ; i <= m ; ++i){
        if(cuenta[i] > lo){
            for(int j = 0 ; j < cuenta[i] - lo ; ++j) tt.pb(ad[i][j]);
        }
    }

    for(int i = 1 ; i <= m ; ++i){
        if(cuenta[i] < lo){
            int ret = 0;
            for(int j = 0 ; j < lo - cuenta[i]; ++j){
                xx[tt[start + j]] = i;
                ret++;
            }
            start += ret;
        }

    }

    cout << lo << " " << start << endl;
    for(int i = 0 ; i < n ; ++i) cout << xx[i] << " ";
    cout << endl;
    return 0;
}
