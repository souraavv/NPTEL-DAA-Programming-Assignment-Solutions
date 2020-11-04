#include <bits/stdc++.h>
#define int long long int
#define inf 1e16
using namespace std;

vector<vector<int> > g;
vector<int> cost;
int ans = -inf;

void dfs(int u, int par, int mxVal) {
 	mxVal = max(mxVal, cost[u]);
  	ans = max(ans, mxVal - cost[u]);
  	for(int v: g[u]) {
  		if(v != par)
          		dfs(v, u, mxVal);
    }	
}

int32_t main() {
  	ios::sync_with_stdio(false);
  	cin.tie(0);
 	int n;
  	cin >> n;
  	g = vector<vector<int> >(n + 10);
  	cost = vector<int> (n + 10);
  	for(int i = 1; i <= n; ++i) {
		cin >> cost[i];
  	}
  
  	int root = -1;
	for(int i = 1, j; i <= n; ++i) {
      	cin >> j;
      	if(j == -1) {
      		root = i;
      		continue;
      	}
      	g[j].push_back(i);
    }
  
    dfs(root, -1, cost[root]);
    cout << ans;
    return 0; 
}
