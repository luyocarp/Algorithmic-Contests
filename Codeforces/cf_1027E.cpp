#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;  
const long long MOD = 998244353;
long long pow2[MAXN];
long long dp[512][512];

void PowerOf2() {
	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i) pow2[i] = pow2[i-1] * 2 % MOD;
}

void initialize() {
	for (int i = 0; i < 512; ++i) 
		for(int j = 0; j < 512; ++j) 
			dp[i][j] = -1;	
}

long long rec(int n, int k) {
	if (k <= 0) return 0;
	if (k >= n) return pow2[n];
	if (dp[k][n] != -1) return dp[k][n];
	long long answer = 0;
	for (int i = 1; i <= k; ++i) answer = (answer + rec(n-i,k)) % MOD;
	return dp[k][n] = answer; 
}

int main() {
	int n, k; 
	scanf("%d %d", &n, &k);
	PowerOf2();
	initialize();
	long long answer = 0;
	for (int col = 1; col <= n; ++col) {
		int row = (k - 1) / col;
		long long to_add = (rec(n, col) - rec(n, col - 1)) * rec(n, row) % MOD;
		if (to_add < 0) to_add += MOD;
		answer = (answer + to_add) % MOD; 
	}
	answer = answer * ((MOD + 1) / 2) % MOD;
	printf("%lld\n", answer);
 	return 0;
}
