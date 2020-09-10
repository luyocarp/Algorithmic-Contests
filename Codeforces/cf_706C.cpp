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
const int MAXN = 1e5 + 1;
const int MN = 1e6 + 2;

ll cc[MAXN];
ll dp[2][MAXN];
string ss[MAXN];
string rr[MAXN];

ll go(int rev, int idx){
    if(idx == 0){
        if(rev == 0) return 0;
        else return cc[0];
    }
    if(dp[rev][idx] != LINF) return dp[rev][idx];
    ll ret = LINF;
    if(rev == 0){
        if(ss[idx] >= rr[idx - 1]) ret = min(ret, go(1, idx - 1));
        if(ss[idx] >= ss[idx - 1]) ret = min(ret, go(0, idx - 1));
    }
    else{
        if(rr[idx] >= rr[idx - 1]) ret = min(ret, go(1, idx - 1) + cc[idx]);
        if(rr[idx] >= ss[idx - 1]) ret = min(ret, go(0, idx - 1) + cc[idx]);
    }
    return dp[rev][idx] = ret;
}

int main(){
    fast_io();
    int n; cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> cc[i];
    string s;
    for(int i = 0 ; i < n ; ++i){
        cin >> s;
        ss[i] = s;
        reverse(s.begin(), s.end());
        rr[i] = s;
    }
    for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < n ; ++j)
        dp[i][j] = LINF;

    ll ans = min(go(0, n - 1), go(1, n - 1));
    if(ans == LINF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
