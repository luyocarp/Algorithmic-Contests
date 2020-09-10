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

int x[1000][1000];
int f_parc[1000][1000];
int c_parc[1000][1000];

int getf(int i, int start, int end){
    if(start > end) return 0;
    if(start == 0) return f_parc[i][end];
    else return f_parc[i][end] - f_parc[i][start - 1];
}

int getc(int j, int start, int end){
    if(start > end) return 0;
    if(start == 0) return c_parc[end][j];
    else return c_parc[end][j] - c_parc[start - 1][j];
}

int main(){
    fast_io();
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> x[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        f_parc[i][0] = x[i][0];
        for(int j = 1; j < m; ++j){
            f_parc[i][j] = f_parc[i][j-1] + x[i][j];
        }
    }

    for(int j = 0; j < m; ++j){
        c_parc[0][j] = x[0][j];
        for(int i = 1; i < n; ++i){
            c_parc[i][j] = c_parc[i-1][j] + x[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            //mira para la izquierda
            if(x[i][j] == 1) continue;
            if(getf(i, 0, j - 1) > 0){
                ++ans;
            }
            //mira para la derecha
            if(getf(i, j + 1, m - 1) > 0){
                ++ans;
            }
            //mira para arriba
            if(getc(j, 0, i - 1) > 0){
                ++ans;
            }
            // mira para abajo
            if(getc(j, i + 1, n - 1) > 0){
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
} 
