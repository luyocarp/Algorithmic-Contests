#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ones(x) __builtin_popcount(x)
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << ": " << x << endl;
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(auto it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define sz(v) int(v.size())


typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< ii, int > tri;
typedef unsigned int uint;


const long double PI = acos(-1);
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;


ll a[102];
ll b[102];
ll c[102];
ll init[20];
ll fin[20];
ll cur[20][20];
ll tmp[20][20];
ll usual[20][20];

void binpow(ll ex, int lado){
	if(ex == 0){
		for(int i = 0; i < lado; ++i){
			for(int j = 0; j < lado; ++j){
				if(i == j) cur[i][j] = 1;
				else cur[i][j] = 0;
			}
		}
		return;
	}
	if(ex % 2 == 0){
		binpow(ex / 2, lado);
		for(int i = 0; i < lado; ++i){
			for(int j = 0; j < lado; ++j){
				tmp[i][j] = cur[i][j];
			}
		}

		for(int i = 0; i < lado; ++i){
			for(int j = 0; j < lado; ++j){
				ll tt = 0;
				for(int r = 0; r < lado; ++r){
					tt += tmp[i][r] * tmp[r][j];
					tt %= MOD;
				}
				cur[i][j] = tt;
			}
		}
	}
	else{
		binpow(ex - 1, lado);
		for(int i = 0; i < lado; ++i){
			for(int j = 0; j < lado; ++j){
				tmp[i][j] = cur[i][j];
			}
		}
		for(int i = 0; i < lado; ++i){
			for(int j = 0; j < lado; ++j){
				ll tt = 0;
				for(int r = 0; r < lado; ++r){
					tt += tmp[i][r] * usual[r][j];
					tt %= MOD;
				}	
				cur[i][j] = tt;
			}
		}
	}		
}

void expo(ll ex, int lado){
	for(int i = 0; i < lado; ++i){
		for(int j = 0; j < lado; ++j){
			cur[i][j] = 0;
		}
	}

	if(lado == 1){
		cur[0][0] = 1;
	}	
	else{
		if(lado == 2){
			cur[0][0] = 1;
			cur[0][1] = 1;
			cur[1][0] = 1;
			cur[1][1] = 1; 
		}
		else{
			cur[0][0] = 1;
			cur[0][1] = 1;
			for(int i = 1; i < lado - 1; ++i){
				cur[i][i - 1] = 1;
				cur[i][i] = 1;
				cur[i][i + 1] = 1;
			}
			cur[lado - 1][lado - 2] = 1;
			cur[lado - 1][lado - 1] = 1;
		}
	}

	for(int i = 0; i < lado; ++i){
		for(int j = 0; j < lado; ++j){
			usual[i][j] = cur[i][j];
		}
	}

	binpow(ex, lado);
}

int main(){
	fast_io();
	int n;
	ll k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i] >> c[i];
	}

	init[0] = 1;
	for(int i = 1; i <= c[0]; ++i) init[i] = 0;
	
	for(int i = 0; i < n - 1; ++i){
		expo(b[i] - a[i], c[i] + 1);
		for(int j = 0; j <= c[i]; ++j){
			ll tt = 0;
			for(int r = 0; r <= c[i]; ++r){
				tt += cur[j][r] * init[r];
				tt %= MOD;				
			}
			fin[j] = tt;
		}
		
		if(c[i] <= c[i + 1]){
			for(int j = 0; j <= c[i]; ++j) init[j] = fin[j];
			for(int j = c[i] + 1; j <= c[i + 1]; ++j) init[j] = 0;
		}
		else{
			for(int j = 0; j <= c[i + 1]; ++j) init[j] = fin[j];
		}	
	}

	expo(k - a[n - 1], c[n - 1] + 1);
	for(int j = 0; j <= c[n - 1]; ++j){
		ll tt = 0;
		for(int r = 0; r <= c[n - 1]; ++r){
			tt += cur[j][r] * init[r];
			tt %= MOD;				
		}
		fin[j] = tt;
	}

	ll ans = fin[0];
	if(ans < 0) ans += MOD;
	cout << ans << endl;
	return 0;
} 
