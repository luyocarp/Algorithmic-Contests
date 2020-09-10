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

string s[500];

int main(){
    fast_io();
    int T; cin >> T;
    while(T--){
        int  m, n ; cin >> m >> n;
        for(int i = 0 ; i < m ; ++i){
            cin >> s[i];
        }
        int ans = 0;
        for(int i = n - 1 ; i >= 0 ; --i){
            for(int j = 0 ; j < m ; ++j){
                if(s[j][i] == '1'){
                    continue;
                }
                else{
                    ++ans;
                    for(int k = j ; k < m ; ++k){
                        if(s[k][i] == '1') s[k][i] = '0';
                        else s[k][i] = '1';
                    }
                    for(int k = 0 ; k < i ; ++k){
                        if(s[j][k] == '1') s[j][k] = '0';
                        else s[j][k] = '1';
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
