#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define EPS 1e-9
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(__typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
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


int a[MAXN];

int n;
int ans;
int pr(int x){
    int y = x - 1;
    y %= ans;
    if(y < 0) y += ans;
    return y;
}

int main(){
    fast_io();
    int m; cin >> n >> m;
    ans = INF;
    int x, y;
    for(int i = 0 ; i < m  ; ++i){
        cin >> x >> y;
        ans = min(y - x + 1, ans);
    }
    a[0] = ans - 1;
    for(int i = 1 ; i < n ; ++i){
        a[i] = pr(a[i - 1]);
    }
    cout << ans << endl;
    for(int i =  0 ; i <n  ;++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
} 
