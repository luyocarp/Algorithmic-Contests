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
typedef pair<ii, int> tri;
typedef pair<int,bool> ib;
typedef unsigned int uint;


const double PI = acos(-1);
const double E = 2.718281828459;
const int  INF = 2e9;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;


int main(){
	fast_io();
	string s;
	cin >> s;
	int len = int(s.size());
	int A = 0, B = 0, c = 0;
	int pos, posig;
	for(int i = 0 ; i < len ; ++i){
		if(s[i] == '+') pos = i;
		if(s[i] == '=') posig = i;
	}

	A = pos;
	B = posig - pos - 1;
	c = len - posig - 1;
	
	if(A + B == c){
		cout << s << endl;
	}
	else if(A + B + 2 == c){
		for(int i = 0 ; i <= A ; ++i) cout << "|";
		cout << "+";
		for(int i = 0 ; i < B ; ++i) cout << "|";
		cout << "=";
		for(int i = 0; i < c - 1; ++i) cout << "|";
	}
	else if(A + B == c + 2){
		if(A >= 2){
			for(int i = 0 ; i < A - 1 ; ++i) cout << "|";
			cout << "+";
			for(int i = 0 ; i < B ; ++i) cout << "|";
			cout << "=";
			for(int i = 0 ; i < c + 1 ; ++i) cout << "|";
		}
		else{
			for(int i = 0 ; i < A ; ++i) cout << "|";
			cout << "+";
			for(int i = 0 ; i < B - 1 ; ++i) cout << "|";
			cout << "=";
			for(int i = 0 ; i < c + 1 ; ++i) cout << "|";
		}
	}
	else{
		cout << "Impossible" << endl;
	}

	return 0;
}
