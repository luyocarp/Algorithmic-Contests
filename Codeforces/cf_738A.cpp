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


string s;
int len;


int try_(int x){
    if(s[x] != 'o'){
        return 0;
    }
    if(x + 1 < len){
        if(s[x + 1] != 'g') return 0;
        else{
            if(x + 2 < len){
                 if(s[x + 2] != 'o') return 0;
                 else{
                    s[x] = s[x + 1] = s[x + 2] = '_';
                    int t = 0;
                    for(int r = 0; r < len; ++r){
                        if((x + 3 + 2 * r) < len  && (x + 3 + 2*r + 1) < len){
                             if(s[x + 3 + 2 * r] != 'g' || s[x + 3 + 2*r + 1] != 'o') break;
                             else{
                                t = r + 1;
                                s[x + 3 + 2 * r] = '_'; s[x + 3 + 2*r + 1] = '_';
                             }
                        }
                        else break;
                    }
                    return 3 + 2 * t;
                 }
            }
            else return 0;
        }
    }
    else return 0;
}

int main(){
    fast_io();
    int n; cin >> n;
    cin >> s;
    len = int(s.size());
    string ans = "";
    for(int i = 0; i < len ;){
        int ret = try_(i);
        if(ret){
            i += ret;
            ans += "***";
        }
        else{
            ans.pb(s[i]);
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}
