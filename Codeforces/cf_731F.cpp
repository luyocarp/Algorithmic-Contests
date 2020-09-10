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

int xx[2 * MAXN];
int cuenta[4 * MAXN];
int mark[4 * MAXN];
int ar[2 * MAXN];
set< int > repetidos;
set< int > :: iterator it;

ll get(int a, int b){
    if(a == 0) return cuenta[b];
    return cuenta[b] - cuenta[a - 1];
}

int main(){
    fast_io();
    int n; cin >> n;
    for(int i = 0 ; i < n ; ++i){
            cin >> xx[i], mark[xx[i]]++;
            repetidos.insert(xx[i]);
    }
    cuenta[0] = mark[0];
    for(int i = 1 ; i < 4 * MAXN ; ++i) cuenta[i] = cuenta[i - 1] + mark[i];
    ll ans = 0;
    int cnt = 0;
    for(it = repetidos.begin() ; it != repetidos.end() ; ++it)
        ar[cnt++] = *it;
    for(int i = 0 ; i < cnt ; ++i){
        ll ret = 0;
        for(int j = ar[i] ; j < 2 * MAXN ; j += ar[i]){
            ret += j * get(j, j + ar[i] - 1);
        }
        ans = max(ans, ret);
    }

    cout << ans << endl;
    return 0;
}
