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

struct Matrix{
    ll mat[2][2];
};

Matrix id;
Matrix nulo;
Matrix fibo;
Matrix lazy[4 * MAXN];
Matrix t[4 * MAXN];
int aa[MAXN];


bool operator != (Matrix x , Matrix y){
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            if(x.mat[i][j] != y.mat[i][j]) return 1;
        }
    }
    return 0;
}

Matrix operator * (Matrix x, Matrix y){
    Matrix ret;
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            ret.mat[i][j] = 0;
            for(int k = 0 ; k < 2 ; ++k){
                ret.mat[i][j] = (ret.mat[i][j] + (x.mat[i][k] * y.mat[k][j])) % MOD;
            }
        }
    }
    return ret;
}

Matrix operator + (Matrix x, Matrix y){
    Matrix ret;
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            ret.mat[i][j] = (x.mat[i][j] + y.mat[i][j]) % MOD;
        }
    }
    return ret;
}

void show(Matrix x){
    cout << x.mat[0][0] << " " << x.mat[0][1] << endl;
    cout << x.mat[1][0] << " " << x.mat[1][1] << endl;
    cout << "-----------------" << endl;
}

Matrix binpow(int n){
    if(n == 1) return fibo;
    if(n & 1){
        return fibo * binpow(n - 1);
    }
    Matrix ans = binpow(n >> 1);
    return ans * ans;
}

void apply(int u, int a, int b){
    t[u] = t[u] * lazy[u];
    if(a != b){
        lazy[u << 1] = lazy[u << 1] * lazy[u];
        lazy[u << 1|1] = lazy[u << 1|1] * lazy[u];
    }
    lazy[u] = id;
}

void build(int u, int a, int b){
    if(a == b){
        t[u] = binpow(aa[a]);
        return;
    }
    int mid = (a + b) >> 1;
    build(u << 1, a, mid);
    build(u << 1|1, mid + 1, b);
    t[u] = t[u << 1] + t[u << 1|1];
}

void update(int u, int a, int b, int i , int j, Matrix val){
    if(lazy[u] != id) apply(u, a, b);
    if(a > j || b < i) return;
    if(a >= i && b <= j){
        lazy[u] = lazy[u] * val;
        apply(u, a, b);
        return;
    }
    int mid = (a + b) >> 1;
    update(u << 1, a, mid, i , j, val);
    update(u << 1|1, mid + 1, b, i, j, val);
    t[u] = t[u << 1] + t[u << 1|1];
}

Matrix query(int u, int a, int b, int i , int j){
    if(a > j || b < i) return nulo;
    if(lazy[u] != id) apply(u, a , b);
    if(a >= i && b <= j) return t[u];
    int mid = (a + b) >> 1;
    Matrix q1 = query(u << 1, a , mid, i , j);
    Matrix q2 = query(u << 1|1, mid + 1, b, i , j);
    return q1 + q2;
}

int main(){
    fast_io();
    int n, m; cin >> n >> m;
    for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
        nulo.mat[i][j] = 0;

    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            if((i + j) % 2 == 0) id.mat[i][j] = 1;
            else id.mat[i][j] = 0;
        }
    }

    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j)
            fibo.mat[i][j] = 1;
    }

    fibo.mat[1][1] = 0;
    for(int i = 1 ; i <= n ; ++i) cin >> aa[i];
    build(1, 1, n);
    for(int i = 0 ; i <= 4 * n ; ++i) lazy[i] = id;
    int op;
    int l, r, x;
    for(int req = 0 ; req < m ; req++){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            Matrix tmp = binpow(x);
            update(1, 1, n, l , r, tmp);
        }
        else{
            cin >> l >> r;
            cout << query(1, 1, n, l, r).mat[0][1] << endl;
        }
    }

    return 0;
}
