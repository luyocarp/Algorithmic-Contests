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
const ll LINF = 1e16 + 5;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MN = 1e6 + 2;

map< char, int > mapa;

void nada(){
	cout << "===" << endl;
}	

int main(){
	fast_io();
	int n; cin >> n;
	string s; cin >> s;
	if(n % 4 != 0){
		nada();
		return 0;
	}

	int ret = n / 4;
	for(int i = 0; i < n; ++i){
		mapa[s[i]]++;
	}

	int a = mapa['A'];
	int c = mapa['C'];
	int g = mapa['G'];
	int t = mapa['T'];
	if(a > ret || c > ret || g > ret || t > ret){
		nada();
		return 0;
	}

	vector< int > v;
	v.clear();

	for(int i = 0; i < n; ++i){
		if(s[i] == '?'){
			v.pb(i);
		}
	}

	int cnt = 0;
	for(int i = 0; i < ret - a; ++i){
		s[v[i + cnt]] = 'A';
	}	
	cnt += ret - a;
	for(int i = 0; i < ret - c; ++i){
		s[v[i + cnt]] = 'C';
	}	
	cnt += ret - c;
	for(int i = 0; i < ret - g; ++i){
		s[v[i + cnt]] = 'G';
	}	
	cnt += ret - g;
	for(int i = 0; i < ret - t; ++i){
		s[v[i + cnt]] = 'T';
	}	
	cnt += ret - t;
	cout <<  s << endl;
	return 0;
} 
