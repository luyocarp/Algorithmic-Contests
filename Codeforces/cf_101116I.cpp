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


map< int, int > :: iterator it;
map< int, int > mapa;
vector< ii > v;
int ans[10];

int main(){
    fast_io();
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        mapa.clear();
        v.clear();
        int x;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < 6 ; ++j){
                cin >> x;
                mapa[x]++;
            }
        }
        for(it = mapa.begin() ; it != mapa.end() ; ++it){
            v.pb(mp(it->snd, -it->fst));
        }

        sort(all(v));
        int k = int(v.size());
        int ap;
        for(int i = 0 ; i < k ; ++i){
            if(v[i].snd == -7){
                ap = v[i].fst;
            }
        }
        int cnt = 0;
        for(int i = k - 1 ; i >= 0 ; --i){
            if(cnt == 6) break;
            if(v[i].fst > ap){
                ans[cnt++] = -v[i].snd;
            }
        }
        if(cnt < 6){
            ans[cnt++] = 7;
            for(int i = k - 1 ; i >= 0 ; --i){
                if(cnt == 6) break;
                if(v[i].fst == ap && v[i].snd != -7){
                    ans[cnt++] = -v[i].snd;
                }
            }
        }
        if(cnt < 6){
            for(int i = k - 1 ; i >= 0 ; --i){
                if(cnt == 6) break;
                if(v[i].fst < ap){
                    ans[cnt++] = -v[i].snd;
                }
            }
        }
        sort(ans, ans + 6);
        for(int i = 0 ; i < 6 ; ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
