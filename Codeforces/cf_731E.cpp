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


ll x[2 * MAXN];
ll a[2 * MAXN];
ll dp[2 * MAXN][2];

ll tree1[4 * 2 * MAXN];
ll tree2[4 * 2 * MAXN];

void build1(int nodo, int a, int b){
    if(a == b){
        tree1[nodo] = -LINF;
        return;
    }
    int mid = (a + b) >> 1;
    build1(nodo * 2 + 1, a , mid);
    build1(nodo * 2 + 2, mid + 1 , b);
    tree1[nodo] = max(tree1[nodo * 2 + 1], tree1[nodo * 2 + 2]);
}

void build2(int nodo, int a, int b){
    if(a == b){
        tree2[nodo] = LINF;
        return;
    }
    int mid = (a + b) >> 1;
    build2(nodo * 2 + 1, a , mid);
    build2(nodo * 2 + 2, mid + 1, b);
    tree2[nodo] = min(tree2[nodo * 2 + 1], tree2[nodo * 2 + 2]);
}

ll get1(int nodo, int a, int b, int i , int j){
    if(b < i || a > j) return -LINF;
    if(b >= j && a <= i) return tree1[nodo];
    int mid = (a + b) >> 1;
    ll q1 = get1(nodo * 2 + 1, a , mid, i , j);
    ll q2 = get1(nodo * 2 + 2, mid + 1, b, i , j);
    return max(q1, q2);
}


ll get2(int nodo, int a, int b, int i ,int j){
    if(b < i || a > j) return LINF;
    if(b >= j && a <= i) return tree2[nodo];
    int mid = (a + b) >> 1;
    ll q1 = get2(nodo * 2 + 1, a , mid , i , j);
    ll q2 = get2(nodo * 2 + 2, mid + 1, b, i, j);
    return min(q1, q2);
}


void update1(int nodo, int a, int b,int pos, ll val){
    if(pos < a || pos > b) return;
    if(a == b){
        tree1[nodo] = val;
        return;
    }
    int mid = (a + b)  >> 1;
    update1(2 * nodo + 1, a, mid, pos, val);
    update1(2 * nodo + 2, mid  + 1, b, pos, val);
    tree1[nodo] = max(tree1[2 * nodo + 1], tree1[2 * nodo + 2]);
}

void update2(int nodo, int a, int b, int pos, ll val){
    if(pos < a || pos > b) return;
    if(a == b){
        tree2[nodo] = val;
        return;
    }
    int mid = (a + b) >> 1;
    update2(2 * nodo + 1, a , mid , pos, val);
    update2(2 * nodo + 2, mid + 1, b, pos, val);
    tree2[nodo] = min(tree2[nodo * 2 + 1], tree2[2 * nodo +2]);
}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i) scanf("%I64d", &x[i]);
    a[0] = x[0];
    for(int i = 1 ; i < n ; ++i) a[i] = a[i-1] + x[i];
    build1(0,0,n - 2);
    build2(0,0,n - 2);
    dp[n - 2][1] = a[n-1];
    dp[n - 2][2] = -a[n-1];
    update1(0,0, n - 2, n - 2,dp[n - 2][2] + a[n - 2]);
    update2(0, 0, n - 2, n - 2, dp[n-2][1] - a[n - 2]);

    for(int i = n - 3 ; i >= 0; --i){
        dp[i][1] = get1(0,0, n - 2, i + 1, n - 2);
        dp[i][1] = max(dp[i][1], a[n - 1]);
        dp[i][2] = get2(0,0, n - 2, i + 1, n - 2);
        dp[i][2] = min(dp[i][2], - a[n - 1]);
        update1(0,0, n - 2, i, dp[i][2] + a[i]);
        update2(0, 0, n - 2, i , dp[i][1] - a[i]);
    }

    printf("%I64d\n", dp[0][1]);
    return 0;
}
