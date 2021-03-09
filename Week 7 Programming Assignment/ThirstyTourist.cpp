#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define inf 1e18

int dp[5001][10001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, n, c;
	cin >> h >> n >> c;

	vector<int> dist(n), cost(n);
	for(int i = 0; i < n; ++i) {
		cin >> dist[i] >> cost[i];
	}
	// dp[i][j] = define as the cost if they are at 
	// the ith shop with rem j litre of water.

	// Transition
	// So at the ith shop The extra j can be from :
	// Case 1 : from any of the shop {0, 1, 2, ... i - 1}
	// Case 2 : If not possible to carry j from any of the {0, 1 ... n - 1} then fill j in the current shop
	// Case 3 : Or What if instead like case 2 where we are filling 
	//          full j litre on the cost of ith shop only
	//          we try to make some litre carried from previous + current
	//          kind of eqn. cost = some_prev_shop * (c - rem) + cur_shop * rem
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= c; ++j) {
			dp[i][j] = inf;
		}
	}
	
	for(int j = 0; j <= c; ++j) {
		dp[0][j] = j * cost[0];
	}

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= c; ++j) {
			if(j + dist[i] - dist[i - 1] <= c) {
				dp[i][j] = min(dp[i - 1][j + (dist[i] - dist[i - 1])], dp[i - 1][dist[i] - dist[i - 1]] + j * cost[i]); // Case 1 & case 2
			}
			else {
				dp[i][j] = min(dp[i][j], dp[i - 1][dist[i] - dist[i - 1]] + j * cost[i]); // Case 2
			}
			if(j > 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost[i]); // Case 3
			}
		}
	}

	cout << dp[n - 1][h - dist[n - 1]] << '\n';
	
}
