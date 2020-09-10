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
const int MAXN = 5e5 + 5;
const int MN = 1e6 + 2;


int n;
ll fenwick_add[MAXN + 1] , fenwick_mul[MAXN +1] ;


void internal_update(int idx, ll mul, ll add){
	while( idx <= n ){
		fenwick_mul[idx] += mul;
		fenwick_add[idx] += add;
		idx |= (idx + 1);
	}
}

void update_interval(int le, int ri, ll val){
	internal_update(le,val, -val*(le-1));
	internal_update(ri,-val, val*ri);
}

ll Recover_interval(int idx){
	ll mul = 0 , add = 0;
	int start = idx;
	while(idx >= 0){
		mul += fenwick_mul[idx];
		add += fenwick_add[idx];
		idx = (idx & (idx + 1) ) - 1;
	}
	return mul*start + add;
}

int main(){
    fast_io();
    int T; cin >> T;
    while(T--){
        int m; cin >> m >> n;
        char c, tr;
        int idx;
        ll s, a, d;
        int r;
        for(int i = 0 ; i < n + 4 ; ++i){
            fenwick_add[i] = fenwick_mul[i] = 0;
        }
        for(int i = 0 ; i < m ; ++i){
            cin >> c;
            if(c == 'U'){
                cin >> tr >> r >> s >> a >> d;
                if(tr == 'E'){
                    if(d >= 2) update_interval(r + 1, r + d - 1, a);
                    update_interval(r, r, s);
                    update_interval(r + d, r + d, -s - a * (d - 1));
                }
                else{
                    if(d >= 2) update_interval(r - d + 2, r, -a);
                    update_interval(r - d + 1, r - d + 1, s + a*(d-1));
                    update_interval(r + 1, r + 1, -s);
                }

            }
            else{
                cin >> idx;
                cout << Recover_interval(idx) << endl;
            }
        }

    }
    return 0;
}
