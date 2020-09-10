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

ll fact[MN];
int primos[MN];
int prime[MN];
int represent[MN];
int cntrep[MN];
int xx[MN];
int gsize[MN];
int cntg[MN];
vector< int > ad[MN];
int asignar[MN];
int len[MN];
int n;
bool already[MN];

int get(int u){
    if(u == 1) return 1;
    else return n / u;
}

int main(){
    scanf("%d", &n);
    fact[0] = 1LL;
    for(int i = 1 ; i <= n ; ++i) fact[i] = (i * fact[i - 1]) % MOD;

    for(int i = 2 ; i * i <= n ; ++i){
        if(!primos[i]){
            for(int j = 2 * i ; j <= n ; j += i) primos[j] = 1;
        }
    }

    int cnt = 0;
    for(int i = 2 ; i <= n ; ++i)
        if(!primos[i]) prime[cnt++] = i;

    for(int i = 1 ; i <= n ; ++i) represent[i] = 1;

    ad[1].pb(1);
    for(int i = 0 ; i < cnt ; ++i){
        for(int j = prime[i] ; j <= n ; j += prime[i]){
            represent[j] *= prime[i];
            ad[j].pb(prime[i]);
        }
    }


    gsize[get(1)] = 1, cntg[1] ++;
    for(int i = 0 ; i < cnt ; ++i) gsize[prime[i]] = get(prime[i]), cntg[get(prime[i])] ++;

    for(int i = 1 ; i <= n ; ++i) scanf("%d", &xx[i]);

    for(int i = 0 ; i <= n ; ++i) len[i] = int(ad[i].size());

    ll ans = 1LL;

    for(int i = 1 ; i <= n ; ++i) asignar[i] = -1;
    for(int i = 1 ; i <= n ; ++i){
        if(xx[i] != 0){
               if(len[i] != len[xx[i]]) ans = 0;
               for(int j = 0 ; j < len[i] ; ++j){
                    if(gsize[ad[i][j]] != gsize[ad[xx[i]][j]])  ans = 0;
                    else{
                        if(asignar[ad[i][j]] != -1){
                            if(asignar[ad[i][j]] != ad[xx[i]][j]) ans = 0;
                        }
                        else{
                               if(already[ad[xx[i]][j]]) ans = 0;
                               else asignar[ad[i][j]] = ad[xx[i]][j], already[ad[xx[i]][j]] = 1;
                        }
                    }
               }
               if(ans == 0) break;
        }
    }
    if(ans == 0){
        printf("%d\n", int(ans));
    }
    else{
        for(int i = 1 ; i <= n ; ++i){
            if(asignar[i] != -1){
                cntg[gsize[i]]--;
            }
        }

        for(int i = 1 ; i <= n ; ++i){
            cntrep[represent[i]]++;
        }
        for(int i = 1 ; i <= n ; ++i){
            if(xx[i] != 0){
                cntrep[represent[i]]--;
            }
        }

        for(int i = 1 ; i <= n ; ++i){
            ans = (ans * fact[cntg[i]]) % MOD;
            ans = (ans * fact[cntrep[i]]) % MOD;
        }

        printf("%d\n", int(ans));
    }

    return 0;
}
