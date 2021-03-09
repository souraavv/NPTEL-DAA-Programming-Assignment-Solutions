#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p, f;
	cin >> n >> p >> f;

	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int fine = 0;
	for(int i = 0; i < n; ++i) {
		int val = a[i] + b[i];
		fine += max(0, (val - p) * f);
	}
	cout << fine << '\n';
}
