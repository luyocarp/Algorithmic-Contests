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


ii ans[2 * MAXN];
int cnt = 0;


int main(){
    fast_io();
    int n, a, b, k; cin >> n >> a >> b >> k;
    string s; cin >> s;
    s.pb('1');
    ++n;
    int last = -1;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if((i - last - 1) >= 0) ans[cnt++] = mp(i - last - 1, last + 1);
            last = i;
        }
    }

    sort(ans, ans + cnt);
    int ret = 0;
    for(int i = 0; i < cnt; ++i){
        ret += ans[i].fst/b;
    }

    cout << ret - a + 1 << endl;
    int curr = 0;
    for(int i = 0; i < cnt; ++i){
        for(int j = 0; j < ans[i].fst/b; ++j){
            cout << ans[i].snd + b * (j + 1) << " ";
            curr++;
            if(curr == (ret - a + 1)) break;
        }
        if(curr == (ret - a + 1)) break;
    }
    cout << endl;
    return 0;
} 
