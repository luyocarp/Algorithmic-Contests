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


int fenwick[MAXN + 5];

int Recovery(int idx){
    int sum = 0;
    while(idx > 0){
        sum += fenwick[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void add(int idx, int val){
    while(idx < MAXN + 4){
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

int main(){
    fast_io();
    int n; cin >> n;
    int x;
    for(int i = 0 ; i < n ; ++i){
        cin >> x;
        add(x, 1);
    }
    int q;
    cin >> q;
    for(int i = 0 ; i < q ; ++i){
        cin >> x;
        if(x > MAXN + 1) cout << n << endl;
        else cout << Recovery(x) << endl;
    }

    return 0;
}
