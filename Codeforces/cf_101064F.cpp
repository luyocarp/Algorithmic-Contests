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


inline int ff(int x){
    return (x + 1)/2;
}


int go(int pasa, int x, int N){
  if(x % 2 == pasa){
    if(pasa == 1){
        return ff(x);
    }
    else return x/2;
  }
  int t;
  if(pasa == 1){
    if(N % 2 == 0) t = 1;
    else t = 0;
    return ff(N) + go(t, x/2, N/2);
  }
  else{
    if(N % 2 == 0) t = 0;
    else t = 1;
    return N/2 + go(t, ff(x) , ff(N));
  }

}

int main(){
    fast_io();
    int T; cin >> T;
    int ans = 0;
    int N, x;

    while(T--){
        cin >> N >> x;
        cout << go(1, x, N) << endl;
    }
    return 0;
}
