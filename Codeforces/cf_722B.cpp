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

int x[MAXN];

set< char > vow;
int cant(string s){
    int len = int(s.size());
    int ans = 0 ;
    for(int i = 0 ; i < len ; ++i){
        if(vow.count(s[i])) ++ans;
    }
    return ans;
}


int main(){
    fast_io();
    vow.insert('a');
    vow.insert('e');
    vow.insert('i');
    vow.insert('y');
    vow.insert('o');
    vow.insert('u');
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> x[i];
    }
    cin.ignore();
    string s;
    for(int i = 0 ; i < n ; ++i){
        getline(cin, s);
        int cnt = 0;
        for(int i = 0 ; i < int(s.size()) ; ++i){
            if(vow.count(s[i])) ++cnt;
        }
        if(cnt != x[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
