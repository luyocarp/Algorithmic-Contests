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


int cnt[MN];
int parc[MN];
int zeros[MN];
int aa[MN];
int df = 0;

int ff(int r){
    int x = parc[MN - 1] - parc[r] + df;
    int z = zeros[r];
    int y = parc[r];
    if(z > (y + x + z - r)) return INF;
    if(x >= z) return x;
    return z;

}

int main(){
    fast_io();
    int n, s; cin >> n >> s;
    --s;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> aa[i];
        if(i == s){
            if(aa[i] != 0) ++ans;
            continue;
        }
        cnt[aa[i]]++;
    }
    df = cnt[0];
    cnt[0] = 0;
    parc[0] = cnt[0];
    zeros[0] = 0;
    for(int i = 1; i < MN; ++i){
        parc[i] = parc[i - 1] + cnt[i];
        zeros[i] = zeros[i - 1];
        if(cnt[i] == 0) zeros[i]++;
    }

    int cur = INF;
    for(int i = 0; i <= 1e6; ++i){
        cur = min(cur, ff(i));
    }
    ans += cur;
    cout << ans << endl;
    return 0;
} 
