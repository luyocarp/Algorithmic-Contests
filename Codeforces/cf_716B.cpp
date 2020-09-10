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


int cnt[50005][30];
int missing[50005];

int main(){
    fast_io();
    string s; cin >> s;
    int n = int(s.size());
    if(n <= 25){
        cout << "-1" << endl;
        return 0;
    }
    for(int i = 0 ; i < 26 ; ++i){
        if(s[i] != '?') cnt[0][s[i] - 'A']++;
        else missing[0]++;
    }
    debug('Z'- 'A');
    for(int i = 1 ; i < n - 25 ; ++i){
        for(int j = 0 ; j < 26 ; ++j){
            cnt[i][j] = cnt[i-1][j];
        }
        if(s[i - 1] != '?') cnt[i][s[i-1] - 'A']--;
        if(s[i + 25] != '?') cnt[i][s[i + 25] - 'A']++;
        missing[i] = missing[i - 1];
        if(s[i - 1] == '?') missing[i]--;
        if(s[i + 25] == '?') missing[i] ++;
    }
    int here = -1;
    for(int i = 0 ; i < n - 25 ; ++i){
        int ret = 0;
        for(int j = 0 ; j < 26 ; ++j){
            if(cnt[i][j] > 0) ++ret;
        }
        if(ret + missing[i] >= 26){
            here = i;
        }
    }

    if(here == -1){
        cout << "-1" << endl;
        return 0;
    }
    else{
        vector< char > falta;
        falta.clear();
        for(int j = 0 ; j < 26 ; ++j){
            if(cnt[here][j] == 0) falta.pb(j + 'A');
        }
        int to = 0;
        for(int i = here ; i <= here + 25 ; ++i){
            if(s[i] == '?') s[i] = falta[to++];
        }
        // fill with A's
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == '?') s[i] = 'A';
        }
        cout << s << endl;
    }

    return 0;

} 
