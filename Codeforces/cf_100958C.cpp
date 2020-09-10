#include <bits/stdc++.h>
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,s,f) for (int i = s; i < f; i++)
#define sz(v) ((int)v.size())
#define ones(x) __builtin_popcount(x)
#define pb push_back
using namespace std;
typedef long long ll;

int n;
ll a[6];
int grid[11];
vector<int> lvl[10];
vector<int> bits2[1 << 6];
int aristas[1 << 6];
int pares;
ll ans;
ll tot = 0;

void solve(int pos,int maxpos){
	ll res = tot;	
	bool flg = false;
	REP(i,0,n){
		int sum = 0;
		REP(j,0,pos){
			if(grid[j] & (1 << i)) sum++;
		}
		if(sum > a[i]){
			flg = true;
			break;
		}
		res -= sum;
	}	
	if(!flg) ans = min(ans, res + pos);

	if(pos == maxpos) return ;
	REP(x,2,n+1){
		for(auto msk : lvl[x]){
			int cur = aristas[msk];
			grid[pos] |= msk;
			
			int comun = pares & cur;
			if(comun != 0) {
				grid[pos] ^= msk;
				continue;
			}
			int npares = pares;
			pares = pares | cur;
			solve(pos+1,maxpos);			
			
			pares = npares;	
			grid[pos] ^= msk;
		}	
	}
}

int main(){
	fast_io();
	cin >> n;
	REP(i,0,n) cin >> a[i];
	for(int i = 0; i < n; ++i) tot += a[i];

	REP(msk, 0, 1 << n){
		lvl[ones(msk)].pb(msk);
		REP(i,0,n) if(msk & (1<<i)) bits2[msk].pb(i);
			
		int msk2 = 0;
		REP(i,0,bits2[msk].size()){
			REP(j,i+1,bits2[msk].size()){
				int u = bits2[msk][i];
				int v = bits2[msk][j];
				if(u > v) swap(u,v);
				int id = u*n + v;
				msk2 = msk2 | (1 << id);
			}
		}
		aristas[msk] = msk2;
	}
	REP(i,0,11) grid[i] = 0;
	ans = 1e18;
	pares = 0;
	solve(0, 10);
	cout << ans << endl;	
	return 0;
} 
