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

ll p[MAXN];
bool used[MAXN];
ll primos[MAXN];
ll sol[MAXN];
int len = 0;
int cnt_primos = 0;
ll mat[2][2];
ll tmp[2][2];
ll base[2][2];
ll ans;
map< ll, int > deco;

ll binpow(ll a, ll n){
    if(n == 0) return 1;
    if(n % 2 == 1){
        return a * binpow(a, n - 1);
    }
    ll ret = binpow(a, n / 2);
    return ret * ret;
}

void bin_matrix(ll n, ll prime){
    if(n == 1){
       for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
            mat[i][j] = base[i][j];
       return;
    }

    if(n % 2 == 0){
        bin_matrix(n / 2, prime);
        for(int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 2 ; ++j){
                tmp[i][j] = 0;
                for(int k = 0 ; k < 2 ; ++k)
                    tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j]) % prime;
            }
        }
    }
    else{
        bin_matrix(n - 1, prime);
        for(int i = 0 ; i < 2 ; ++i){
            for(int j = 0 ; j < 2 ; ++j){
                tmp[i][j] = 0;
                for(int k = 0 ; k < 2 ; ++k){
                    tmp[i][j] = (tmp[i][j] + mat[i][k] * base[k][j]) % prime;
                }
            }
        }
    }

    for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < 2;  ++j)
        mat[i][j] = tmp[i][j];

}

ll fibo(ll n, ll prime){
    if(n == 0) return 0;
    bin_matrix(n, prime);
    return mat[0][1];
}

bool isK(ll x,ll prime){
    if(fibo(x, prime) == 0 && fibo(x + 1, prime) == 1) return 1;
    else return 0;
}

ll K(ll prime){
    // Starting with F0 = 0, F1 = 1
    if(prime == 2) return 3;
    if(prime == 5) return 20;
    ll rt = LINF;
    if(prime % 5 == 1 || prime % 5 == 4){
        for(ll i = 1 ; i * i <= prime - 1; ++i){
            if((prime - 1) % i != 0) continue;
            if(isK(i, prime)){
                rt = min(rt, i);
            }
            if((prime - 1) != (i * i) && isK((prime - 1) / i, prime)){
                rt = min(rt, (prime - 1) / i);
            }
        }
    }
    else{
        for(ll i = 1 ; i * i <= (2 * prime + 2) ; ++i){
            if((2 * prime + 2) % i != 0) continue;
            if((prime + 1) % i != 0 && isK(i, prime)){

                rt = min(rt, i);
            }
            if((prime + 1) % ((2 * prime + 2) / i) != 0 && (2 * prime + 2) != (i * i) && isK((2 * prime + 2) / i, prime)){
                rt = min(rt, (2 * prime + 2)/i);
            }
        }

    }
    return rt;
}

void ff(int prime, ll r){
    ll rr = r;
    ll tt = 1;
    while(rr % prime == 0){
        tt *= prime;
        rr /= prime;
    }
    ll ret = K(prime);
    ret *= (tt / prime);
    sol[len++] = ret;
}

int main(){
    freopen("fibonacci.in", "r", stdin);
    freopen("fibonacci.out", "w", stdout);
    fast_io();
    // Beg of preprocessing
    used[0] = used[1] = 1;
    for(int i = 2 ; i < MAXN ; ++i){
        if(!used[i]){
            for(int j = 2 * i ; j < MAXN ; j += i)
                used[j] = 1;
        }
    }

    for(int i = 2 ; i < MAXN ; ++i){
        if(!used[i]) primos[cnt_primos++] = i;
    }
    // Base for Fibonacci
    for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
            base[i][j] = 1;
    base[1][1] = 0;

    // End of preprocessing
    ll n;
    cin >> n;
    ll r = n;
    int cnt = 0;
    for(int i = 0 ; i < cnt_primos ; ++i){
        if(primos[i] * primos[i] > n) break;
        if(n % primos[i] == 0){
            p[cnt++] = primos[i];
            while(n % primos[i] == 0) n /= primos[i];
        }
    }
    if(n > 1) p[cnt++] = n;
    ans = 1;
    for(int i = 0 ; i < cnt ; ++i){
        ff(p[i], r);
    }

    for(int i = 0 ; i < len ; ++i){
        for(int j = 0 ; j < MAXN ; ++j){
            if(primos[j] * primos[j] > sol[i]) break;
            if(sol[i] % primos[j] == 0){
                int ex = 0;
                while(sol[i] % primos[j] == 0){
                    ex++;
                    sol[i] /= primos[j];
                }
                if(!deco.count(primos[j])) deco[primos[j]] = ex;
                else deco[primos[j]] = max(deco[primos[j]], ex);
            }
        }
        if(sol[i] > 1){
            if(!deco.count(sol[i])) deco[sol[i]] = 1;
            else deco[sol[i]] = max(deco[sol[i]], 1);
        }
    }

    for(auto it = deco.begin() ; it != deco.end() ; ++it){
        ans *= binpow(it -> fst, it -> snd);
    }

    cout << ans << endl;
    return 0;
} 
