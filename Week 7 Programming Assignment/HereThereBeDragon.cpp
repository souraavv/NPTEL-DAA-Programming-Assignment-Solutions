/*
Here there be Dragons
(IOI Training Camp, 2012)

The kingdom is falling into ruin. People live in fear. Dragons pillage, kill, and just generally cause as much havoc as they possibly can. The king has just sent out a royal decree:

To any man out there who is able to bring me the heads of K dragons, I shall bequeath a lordship–to him, his sons and his grandsons, till the end of time.
Having seen this royal decree, and knowing that you are capable of killing dragons thanks to your extensive medieval combat training, you set out on a quest to hunt down the evil creatures. Being a busy kind of guy, you would like to complete your quest quickly and kill K dragons through the shortest route.

The kingdom is arranged in a grid with R rows, numbered 0 to R-1, and C columns, numbered 0 to C-1 You start your quest at the top left corner of the grid, (0,0).

The total number of dragons in the kingdom is D, of which you have to kill K. Dragons are very territorial in nature, so each row of the grid contains at most one dragon. Also, since the kingdom is situated on a hill, you travel only downwards on the grid, though you may move left or right as you please.

You are told that no two dragons are on the same row of the grid. Also, no dragon is at position (0,0).

For example, suppose the grid has 5 rows and 5 columns with 3 dragons, of which you have to kill any 2. The three dragons are located at (1,4), (2,3) and (4,4), as shown below. In this case, your shortest route is to take 7 steps and kill the dragons in row 1 and row 2. Killing any other combination of 2 dragons takes 8 steps, so this is the minimum possible. Note that once you've killed K dragons, you don't incur any cost to return home. You just want to find how long it takes to do all the killing. 

Solution hint
Number the dragons 1,2,…,D in ascending order of rows. Let mindist(i,j) denote the minimum distance travelled when the jth dragon killed is dragon i. Recall the constraint that there is no dragon at (0,0). Use dynamic programming to compute mindist(i,j) for all values of i and j, then find the minimum among mindist(i,K) for all i ≥ K.

Input format
Line 1 : Four space-separated integers, R, C, K and D.
Lines 2 to D+1 : Each line has two-space separated integers r and c, the row and column of the corresponding dragon.
Output format
A single integer, the minimum total distance travelled to kill K dragons.

Test Data:
In all testcases, K ≤ D ≤ R, and, for each dragon position (r,c), 0 ≤ r < R, and 0 ≤ c < C.
In all testcases, 1 ≤ K,D ≤ 300.
In 60% of the testcases, 1 ≤ R,C ≤ 300. In the remaining testcases, 1 ≤ R,C ≤ 100000.
No two dragons will be on the same row.
No dragon will be at position (0,0).
Sample Input:
5 5 2 3
1 4
4 4
2 3
Sample Output:
7

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define all(v) (v).begin(), (v).end()
#define pb push_back
const int inf=INT_MAX;

int u, v;
int dp[350][350],dist[350][350];


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    int r,c,k,d;
    cin>>r>>c>>k>>d;
 
    vpi a;
    a.pb({0,0});
    for(int i=0;i<d;++i){
        cin>>u>>v;
        a.pb({u,v});
    }
    
    sort(all(a));

    for(int i=1;i<=d;++i)
        for(int j=1;j<=d;++j)
            if(not dist[i][j])
                dist[i][j]=dist[j][i]=abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
                    
        
    for(int i=1;i<=d-k+1;++i)
        dp[1][i]=a[i].first+a[i].second;
      
 
    for(int i=2;i<=k;++i){
        for(int j=i;j<=d;++j){
            int temp=inf;
            for(int p=j-1;p>=1;--p){
                    if(dp[i-1][p] and temp>dist[p][j]+dp[i-1][p])
                        temp=dist[p][j]+dp[i-1][p];
            }
            dp[i][j]=temp;
        }
    }
    
    int ans=inf;
    for(int i=k;i<=d;++i)ans=min(ans,dp[k][i]);
    cout<<ans<<"\n";
    
    return 0;
} 
