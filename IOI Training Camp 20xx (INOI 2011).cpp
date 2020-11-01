// Sourav Sharma


// Mark the Repo Star if you like ....


#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define inf 1e16;

int32_t main(){
	
	int n, k;
	cin >> n >> k;
	vector<int> val(n);
	for(int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	int dp[n + 1][k + 1];
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= k; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = val[0];
	for(int i = 1; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][0] + val[i], val[i]); 
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i][j - 1];
			if(i - 1 >= 0) {
				dp[i][j] = max({dp[i][j], dp[i - 1][j - 1], dp[i - 1][j] + val[i]});
			}
		}
	}
	int ans = -inf;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, dp[i][k]);
	}
	cout << ans << '\n';
	return 0;
}
