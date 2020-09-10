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


int x_(char c){
    if(isupper(c) || islower(c)) return 0;
    if(c == ')' || c == '(') return 0;
    return 1;
}

int main(){
    fast_io();
    int n ; cin >> n;
    string s; cin >> s;
    int c0 = 0 , cp = 0;
    int rp = 0 , r0 = 0;
    int pa = 0;
    int ff = 0;
    int lastp = -1;
    for(int i = 0 ; i < n ; ++i){
        if(x_(s[i])){
            c0 = max(c0, r0);
            r0 = 0;
        }
        else{
            if(s[i] == '('){
                pa = 1;
                c0 = max(c0, r0);
                r0 = 0;
            }
            else if(s[i] == ')'){
                pa = 0;
            }
            else{

                if(!pa) r0++;
                else r0 = 0;
            }
        }
    }
    c0 = max(c0, r0);

    vector< ii > v;
    int tu = 0;
    int fr = 0, sr = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '('){
            fr = i;
        }
        else if(s[i] == ')'){
            sr = i;
            v.pb(mp(fr, sr));
            ++tu;
        }
    }

    for(int i = 0 ; i < tu ; ++i){
        if(v[i].snd > v[i].fst + 1){
            string t = s.substr(v[i].fst + 1, v[i].snd - v[i].fst - 1);
            int len = int(t.size());
            for(int j = 0 ; j < len ; ++j){
                if(x_(t[j])) t[j] = ' ';
            }
            int ok = 1;
            for(int j = 0 ; j < len ; ++j){
                if(t[j] != ' ' && ok){
                    cp++;
                    ok = 0;
                }
                else if(t[j] == ' '){
                    ok = 1;
                }
            }
        }
    }
    cout << c0 << " " << cp << endl;
    return 0;
}
