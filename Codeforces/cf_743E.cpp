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
#define debug(x) cout << #x << ": " << x << endl;
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
const ll LINF = 1e16 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int a[1001];
int dp[1001][512];
int cant[10][1002];
int last[10][1002][1002];
int tot = 0;

void process(int n){
     for(int i = 1; i <= 8; ++i){
     	for(int j = 0; j < 1002; ++j){
     		for(int k = 0; k < 1002; ++k) 
     		last[i][j][k] = -1;
     	}	
     
     }

     for(int j = 1; j <= 8; ++j){
             if(a[0] == j){
                     cant[j][0] = 0;        
             }
             else cant[j][0] = -1;                             
     }
     
     for(int len = 1; len < n; ++len){
            for(int j = 1; j <= 8; ++j){
                    if(a[len] == j){
                         cant[j][len] = len;          
                    }
                    else{
                         cant[j][len] = cant[j][len - 1];     
                    }
            }
     }
    
     for(int len = 0; len < n; ++len){
             for(int i = 1; i <= 8; ++i){
             		 last[i][0][len] = len + 1;
                     last[i][1][len] = cant[i][len];      
             }        
     }
     
     for(int len = 0; len < n; ++len){
             for(int x = 2; x < n; ++x){
                     for(int i = 1; i <= 8; ++i){
                             int tt = last[i][x - 1][len];
                             if(tt <= 0) last[i][x][len] = -1;
                             else last[i][x][len] = cant[i][tt - 1];                             
                     }        
             }
     }     
}

int go(int x, int need, int len){
	if(x == 0) return tot;
    if(len < 0) return -1;
    if(need == 0) return 0;
    if(dp[len][need] != -INF) return dp[len][need];
    int ret = -1;
    for(int i = 1; i <= 8; ++i){
            if(need & (1 << i)){
                 int late1 = last[i][x][len];
                 int late2 = last[i][x + 1][len];
                 if(late1 != -1){
                            int ret1 = -1;
                            if(late1 == 0){
                                     if((need ^ (1 << i)) == 0) ret1 = 0;
                                     else ret1 = -1;    
                            }
                            else{
                                 ret1 = go(x, need ^ (1 << i), late1 - 1);         
                            }
                            if(ret1 != -1){
                                    ret = max(ret, x + ret1);        
                            }
                 }          
                 if(late2 != -1){
                          int ret2 = -1;
                          if(late2 == 0){
                                   if((need ^ (1 << i)) == 0) ret2 = 0;
                                   else ret2 = -1;         
                          }
                          else{
                               ret2 = go(x, need ^ (1 << i), late2 - 1);
                          } 
                          if(ret2 != -1){
                                  ret = max(ret, x + 1 + ret2);        
                          }         
                 }
            }        
    }
    return dp[len][need] = ret; 
}


int main(){
    fast_io();
    int n; cin >> n;
    set< int > ss;
    ss.clear(); 
    for(int i = 0; i < n; ++i){
            cin >> a[i];
            ss.insert(a[i]);
    }
    tot = int(ss.size());
    process(n);
    int lo = 0, hi = n;
    while(lo < hi){
             int mid = (lo + hi + 1) >> 1;
             for(int i = 0; i < n; ++i){
                     for(int j = 0; j < 512; ++j){
                             dp[i][j] = -INF;        
                     }        
             }         
             
             int ans = go(mid, 510, n - 1);
             if(ans == -1) hi = mid - 1;
             else lo = mid;             
    }  
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 512; ++j){
            dp[i][j] = -INF;        
        }        
    }     
    cout << go(lo, 510, n - 1) << endl; 
    return 0;
} 
