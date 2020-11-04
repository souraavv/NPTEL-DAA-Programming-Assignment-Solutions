#include <bits/stdc++.h>
using namespace std;

#define hey(x) cerr << "[" #x << " : " << x << "]\n";
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
#define inf 1e12
#define F first
#define S second
#define PI 3.1415926535897932384626
#define bpc(x) __builtin_popcountll(x)
#define Cout cout << fixed << setprecision(12)
#define fill(v, val) memset((v), val, sizeof(v))
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << "[" << #x << " : " << x << "], [" << #y << " : " << y << "]\n";

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

void print(vi &a, int start = 0) {
	cerr << "Print\n[";
	for(int i = start; i < SZ(a); ++i) {
		cerr << a[i] << " ]"[i == SZ(a) - 1];
	}
	cerr << "\n";
}

bool isStart(char c) {
	string match = "adgjmptw";
	for(char d : match)
		if(c == d)
			return 1;
	return 0;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	map<char, int> keyPad;
	int val = 1;
	for(int i = 0; i < 26; ++i) {
		char c = 'a' + i;
		if(isStart(c)) {
			++val;
			keyPad[c] = val;
		}
		else {
			keyPad[c] = val;
		}
	}
	map<string, int> ans;
	while(t--) {
		string s;
		cin >> s;
		string temp = "";
		for(char c: s) {
			temp += char(keyPad[c] + '0');
		}
		ans[temp]++;
	}	
	string finaAns = "";
	int length = 0;
	for(auto it: ans) {
		if(it.second > length) {
			finaAns = it.first;
			length = it.second;
		}
	}
	cout << finaAns << '\n';
	return 0;
}
