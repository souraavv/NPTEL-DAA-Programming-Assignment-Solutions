#include<bits/stdc++.h>
#define int long long int 
#define inf 1e16
using namespace std;

vector<vector<pair<int, int> > > g;

int32_t main() {
 	int s, d;
  	cin >> s >> d;
  	int n, m;
  	cin >> n >> m;
  	vector<int> greenLight(n + 1);
  	g = vector<vector<pair<int, int> > > (n + 1);
  	for(int i = 1; i <= n; ++i) {
  		cin >> greenLight[i];
  	}
  	for(int i = 1; i < m; ++i) {
  		int u, v, w;
      	cin >> u >> v >> w;
      	g[u].push_back({v, w});
     	g[v].push_back({u, w});
    }
  	
    cout << dist[d] << '\n';
   	return 0;
}
