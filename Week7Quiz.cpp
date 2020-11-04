An alignment between two strings w1 and w2 (over the alphabet {a,b,c,...,z}) is obtained by inserting hyphens in the two strings such that the modified strings align (i.e., the modified strings are of equal length, and at each position, either both strings have the same letter or one of the strings has a hyphen).

Here are three examples of alignments. The first is between ocurrance and occurrence and the second and third are between ctatg and ttaagc.

(1)	oc-urr-ance	   	(2)	ct-at-g-	   	(3)	ctat---g-
occurre-nce			-tta-agc			---ttaagc
A mismatch in an alignment is a position where one of modified strings has a hyphen and the other does not. There are three mismatches in the first alignment given above, five mismatches in the second, and seven mismatches in the third.


dp[i][j] = dp[i - 1][j - 1] ; if(s[i] == d[j])
         = 1 + min(dp[i - 1][j], dp[i][j - 1]) ; o/w

/* Program : */

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define vvpi vector<vector<pair<int, int> > >
#define all(v) (v).begin(), (v).end()	
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int)(x).size()
#define inf 1e16
#define F first
#define S second
#define bpc(x) __builtin_popcountll(x)
#define Cout cout << fixed << setprecision(12)
#define fast ios::sync_with_stdio(false); cin.tie(0);

#define show(x) cerr << "[" #x << " : " << x << "]\n";
#define hey(x) show(x);
#define hey2(x, y) show(x); hey(y);
#define hey3(x, y, z) show(x); hey(y, z);
#define hey4(x, y, z, w) show(x); hey3(y, z, w);


const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

template <typename T>
void hi(T a) {
	cout << a << '\n';
}
template <typename T, typename... S>
void hi(T a, S... b) {
	cout << a << ' ';
	hi(b...);
}

void print(vi &a, int start = 0) {
	cout << "Erase at last: \n";
	cerr << "Print\n[";
	for(int i = start; i < SZ(a); ++i) {
		cerr << a[i] << " ]"[i == SZ(a) - 1];
	}
	cerr << "\n";
}

int32_t main(){
	
	string s, d;
	cin >> s >> d;

	int n = SZ(s), m = SZ(d);
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			dp[i][j] = inf;
		}
	}
	for(int i = 0; i <= n; ++i)
		dp[i][0] = i;
	for(int i = 0; i <= m; ++i) 
		dp[0][i] = i;
	
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i - 1] == d[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << dp[n - 1][m - 1] << '\n';
	return 0;
}
