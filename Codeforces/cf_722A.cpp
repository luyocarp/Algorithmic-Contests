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


vector<string> ar12;
vector<string> ar24;
int c12 = 0;
int c24 = 0;

int ffind(string s , string t){
    int len = int(s.size());
    int tt = 0;
    for(int i = 0 ; i < len  ; ++i){
        if(s[i] != t[i]) ++tt;
    }
    return tt;
}

string convert(int x){
    string ans;
    if(x < 10){
        ans.pb('0');
        ans.pb(x + '0');
    }
    else{
        ans.pb(x/10 + '0');
        ans.pb((x %10) + '0');
    }
    return ans;
}

int main(){
    fast_io();
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 1 ; i <= 12 ; ++i){
        for(int j = 0 ; j < 60 ; ++j){
            string t = "";
            t += convert(i);
            t += ':';
            t += convert(j);
            ++c12;
            ar12.pb(t);
        }
    }


    for(int i = 0; i <= 23 ; ++i){
        for(int j = 0 ; j < 60 ; ++j){
            string t = "";
            t += convert(i);
            t += ':';
            t += convert(j);
            ++c24;
            ar24.pb(t);
        }
    }

    string ans;
    if(n == 12){
        int dif = 100;
        for(int i = 0 ; i < c12 ; ++i){
            int nd = ffind(s, ar12[i]);
            if(nd < dif){
                dif = nd;
                ans = ar12[i];
            }
        }
    }
    else{
        int dif = 100;
        for(int i = 0 ; i < c24 ; ++i){
            int nd = ffind(s, ar24[i]);
            if(nd < dif){
                dif = nd;
                ans = ar24[i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
