#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);    
    int n;
    cin >> n; 
    int grid[n + 1][2];
    // Read the input 
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> grid[i][j];
        }
    }
    
    /* 
    Defn. 
        dp[i] represents the maximum score that can be achieved if we completely fill till the column i.
    
    Transition: 
        If we are on column i, we can either use vertical domino (2 X 1) on the ith column and till i - 1 we are filled completely.
        or
        If we want to use two 1 X 2 domino (horizontal) then we will ask for the maximum score than can be form till i - 2.
        
        Pick the maximum of these two choices.
    
    Result: 
        We need to fill everything, thus answer is present at dp[n - 1]
    
    Time complexity : 
        O(n)
    Space Complexity:
        O(n)
    
    
    */ 
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // Filling base cases.
    dp[0] = abs(grid[0][0] - grid[0][1]);
    dp[1] = abs(grid[0][0] - grid[1][0]) + abs(grid[0][1] - grid[1][1]);
    for (int col = 1; col < n; ++col) {
        dp[col] = max(dp[col], dp[col - 1] + abs(grid[col][1] - grid[col][0]));
        if (col - 2 >= 0) {
            dp[col] = max(dp[col], dp[col - 2] + abs(grid[col - 1][0] - grid[col][0]) + abs(grid[col - 1][1] - grid[col][1]));
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
