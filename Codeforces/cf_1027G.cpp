#include <bits/stdc++.h>

using namespace std;


void clr(vector< long long >& a, vector< long long >& b) {
	a.clear();
	b.clear();
}

void compute(vector< long long >& Primes, vector < long long >& divisors, long long m) {
	long long value_m = m;
	for(long long i = 1; i * i <= m; ++i) {
		if(m % i == 0) {
			if(m == i * i) divisors.push_back(i);
			else {
				divisors.push_back(i);
				divisors.push_back(m / i);
			}
		}

		if(i > 1 && value_m % i == 0) {	
			Primes.push_back(i);
			while(value_m % i == 0) value_m /= i;
		}
	}
	if(value_m > 1) Primes.push_back(value_m);
}

long long lcm(long long x, long long y) {
	return x * (y / __gcd(x, y));
}

long long mult(long long a, long long e, long long m) {
	if(e < 1024) return a * e % m;
	long long le = mult(a, e >> 10, m) * 1024 % m;
	long long ri = mult(a, e ^ ((e >> 10) << 10), m);
	return (le + ri) % m;
}

long long binpow(long long a, long long e, long long m) {
	if(e == 0) return 1;
	if(e & 1) return mult(a, binpow(a, e - 1, m), m);
	long long answer = binpow(a, e / 2, m);
	return mult(answer, answer, m);
}

unordered_map< long long, long long > umap;
long long OrderOf(long long x, long long n, long long phi_n) {
	if(umap.count(n)) return umap[n];
	long long ret = phi_n;
	for(long long i = 1; i * i <= phi_n; ++i) {
		if(i > ret) break;
		if(phi_n % i == 0) {
			if(phi_n == i * i) {
				if(binpow(x, i, n) == 1) ret = min(ret, i);
			}
			else {
				if(binpow(x, i, n) == 1) ret = min(ret, i);
				if(binpow(x, phi_n/i, n) == 1) ret = min(ret, phi_n/i);
			}
		}
	}	
	return umap[n] = ret;
}

int main() {
	long long m, x;
	cin >> m >> x;
	vector < long long > PrimeFactors;
	vector< long long > divisors;
	
	clr(PrimeFactors, divisors);	
	compute(PrimeFactors, divisors, m);
	
	long long answer = 0;
	for(long long d : divisors) {
		long long numerator_d = 1;
		long long denominator_d = 1;
	
		for(long long p : PrimeFactors) {
			if(d % p != 0) continue;
			int exponent = 0;			
			long long value_d = d;
			long long ret = 1;
			long long old_ret = 1;
			while(value_d % p == 0) {
				value_d /= p;
				ret *= p;
				exponent ++;
			}
			old_ret = ret;
			ret /= p;
			ret *= (p - 1);
			numerator_d = numerator_d * ret;
			denominator_d = lcm(denominator_d, OrderOf(x, old_ret, ret));
		}
		
		answer = answer + numerator_d / denominator_d;
	}

	cout << answer << endl;
	return 0;
}
