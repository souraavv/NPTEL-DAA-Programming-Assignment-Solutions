/*

Road Trips and Museums
Indian National Olympiad in Informatics 2018

Lavanya and Nikhil have K months of holidays ahead of them, and they want to go on exactly K road trips, one a month. They have a map of the various cities in the world with the roads that connect them. There are N cities, numbered from 1 to N. We say that you can reach city B from city A if there is a sequence of roads that starts from city A and ends at city B. Note that the roads are bidirectional. Hence, if you can reach city B from city A, you can also reach city A from city B.

Lavanya first decides which city to start from. In the first month, they will start from that city, and they will visit every city that they can reach by road from that particular city, even if it means that they have to pass through cities that they have already visited previously. Then, at the beginning of the second month, Nikhil picks a city that they haven't visited till then. In the second month, they first fly to that city and visit all the cities that they can reach from that city by road. Then, in the third month, Lavanya identifies a city, and they fly there and visit all cities reachable from there by road. Then in the fourth month it is Nikhil's turn to choose an unvisited city to start a road trip, and they alternate like this. Note that the city that they fly to (that is, the city from where they start each month's road trip) is also considered as being visited.

Each city has some museums, and when they visit a city for the first time, Lavanya makes them visit each of the museums there. Lavanya loves going to museums, but Nikhil hates them. Lavanya always makes her decisions so that they visit the maximum number of museums possible that month, while Nikhil picks cities so that the number of museums visited that month is minimized.

Given a map of the roads, the number of museums in each city, and the number K, find the total number of museums that they will end up visiting at the end of K months. Print -1 if they will have visited all the cities before the beginning of the Kth month, and hence they will be left bored at home for some of the K months.

Solution hint
Use BFS/DFS to identify the connected components of the underlying undirected graph. Sort the components based on how many museums they contain and make appropriate choices for Lavanya and Nikhil each month.

Input format
The first line of each testcase contains three integers: N, M and K, which represents the number of cities, number of roads and the number of months.
The ith of the next M lines contains two integers, ui and vi. This denotes that there is a direct road between city ui and city vi.
The next line contains N integers, the ith of which represents the number of museums in city i.
Output format
If they can go on K road trips, output a single line containing a single integer which should be the total number of museums they visit in the K months. Output -1 if they can't go on K road trips.

Constraints
1 ≤ T ≤ 3
1 ≤ N ≤ 106
0 ≤ M ≤ 106
1 ≤ K ≤ 106
1 ≤ ui, vi ≤ N
There is no road which goes from one city to itself. ie. ui ≠ vi.
There is at most one direct road between a pair of cities.
0 ≤ Number of museums in each city ≤ 1000
Sum of N over all testcases in a file will be ≤ 1.5 * 106

Sample input 1
10 10 3
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
Sample output 1
345

Sample input 2
10 10 2
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
Sample output 2
240

Sample input 3
10 10 5
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
Sample output 3
-1

*/

#include <bits/stdc++.h>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define pb push_back


vvi g;
vi val, vis;
int sum=0;

void dfs(int u){
    if(vis[u])return;
    vis[u]=1,sum+=val[u];
    for(int v: g[u])
      if(not vis[v])dfs(v);
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    
    g=vvi(n+1),val=vi(n+1);
    
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
    }

    for(int i=1;i<=n;++i)cin>>val[i];
    
    
    vi ans;
    vis=vi(n+1,0);
    for(int i=1;i<=n;++i){
        if(not vis[i]){
            sum=0;
            dfs(i);
            ans.pb(sum);
        }
    }
    
    sort(all(ans));
    int fans=0;
    if(ans.size()<k)cout<<"-1\n";
    else{
        int n=ans.size();
        int p=k/2;
        for(int i=0;i<p;++i)fans+=ans[i];
        if(k%2)p++;
        
        for(int i=n-1;i>=n-p;--i)fans+=ans[i];
        
        cout<<fans<<"\n";
    }
    
    
    return 0;
}
