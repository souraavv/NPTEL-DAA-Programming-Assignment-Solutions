// Name : Sourav Sharma

#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
	int n;
	cin >> n;
	vector<pair<int, int> > store;
	for(int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		store.push_back({l, r + l - 1});
	} 
  	auto go = [&](pair<int, int>& a, pair<int, int>& b) {
  		return a.second < b.second;
  	};
	sort(store.begin(), store.end(), go);
	int lastVis = 0, cnt = 1;
	for(int i = 1; i < n; ++i) {
		if(store[i].first > store[lastVis].second) {
			cnt++;
			lastVis = i;
		}
	}
	cout << cnt << '\n';
	return 0;
}
