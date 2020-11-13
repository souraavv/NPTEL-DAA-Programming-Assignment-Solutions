#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define inf 1e16

const int N = 1e4 + 10;
const int K = 1e2 + 10;
int cache[N][K];

int n, k;
vector<int> val;

int finaAns = -inf;

int dp(int i, int j) {
    if(i < 0)
        return -inf;
    int& ans = cache[i][j];
    if(ans != -1) {
        return ans;
    }
    if(j == 0) 
        return ans = max(dp(i - 1, 0) + val[i], val[i]);    
    else
        return ans = max({dp(i, j - 1), dp(i - 1, j - 1), dp(i - 1, j) + val[i]});
}

int32_t main(){
    cin >> n >> k;
    val = vector<int> (n);
    for(int i = 0; i < n; ++i)
        cin >> val[i];

    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < K; ++k) {
            cache[i][k] = -1;
        }
    }
    cache[0][0] = val[0];
    dp(n - 1, k);
    
    for(int i = 0; i < n; ++i)
        finaAns = max(finaAns, cache[i][k]);
    cout << finaAns << '\n';

    return 0;
}
