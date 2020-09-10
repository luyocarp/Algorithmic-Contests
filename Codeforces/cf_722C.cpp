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


ll x[MAXN];
int p[MAXN];
set< ii > inter;
map< ll , int> mapa;
set< ii > :: iterator it;
map< ll, int > :: iterator itr;
ll s[MAXN];


ll get(ll r, ll l){
    if(l == 0) return s[r];
    else return s[r] - s[l - 1];
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i) scanf("%I64d", &x[i]);
    for(int i = 0 ; i < n ; ++i) scanf("%d", &p[i]);

    s[0] = x[0];
    for(int i = 1 ; i < n ; ++i) s[i] = s[i - 1] + x[i];
    inter.insert(mp(0, n - 1));
    mapa[get(n - 1, 0)] = 1;
    for(int i = 0 ; i < n ; ++i){
        --p[i];
        it = inter.upper_bound(mp(p[i], INF));
        --it;
        int u = it -> fst;
        int v = it -> snd;
        ll tmp = get(v, u);
        inter.erase(it);
        if(p[i] - 1 >= u) inter.insert(mp(u, p[i] - 1));
        if(v >= p[i] + 1)inter.insert(mp(p[i] + 1, v));
        if(mapa[tmp] == 1) mapa.erase(tmp);
        else mapa[tmp]--;
        if(p[i] - 1 >= u) mapa[get(p[i] - 1, u)] ++;
        if(v >= p[i] + 1) mapa[get(v, p[i] + 1)] ++;
        if(inter.empty())printf("0\n");
        else{
            itr = mapa.end();
            --itr;
            printf("%I64d\n", itr -> fst);
        }
    }
    return 0;
}
