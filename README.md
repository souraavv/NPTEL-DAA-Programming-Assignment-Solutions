Sourav Sharma (UIIT Shimla)

Email: souravsharma2468@gmail.com

NPTEL-Design Analysis And Algorithm - Programming Assignments Solutions

Certificate Link : [Click here](https://github.com/souraavv/NPTEL/blob/main/Algorithm/DAAlgorithms.pdf)

--------------------------------------------------------------------------------

# **Problem 1: Book Cartons**


## **Prerequisite:** Binary Search + Greedy.



**Problem Statement: Given m cartons and each containing some bi books.We have to assign them to k students such that the student who got the maximum books that maximum value is the minimum possible in all possible valid allocation of books. Maybe this statement is confusing at first glance. Let me go through an example.**



Ex.  5 cartons, 3 students.   Cartons : {100, 200, 300, 400, 500}


Possible Allocations : 

    Allocation : {100}, {200}, {300, 400, 500} 

    Maximum books to a single student : 300 + 400 + 500 =   1200



Maybe we can do somewhat better in lowering the maximum.

    {100, 200}, {300, 400}, {500}. 

    Maximum books to a single student : 300 + 400 = 700



Can we bring max to some more smaller value ?

    {100, 200, 300}, {400}, {500}

    Max : 100 + 200 + 300 = 600



So all above are valid allocation in the sense we are allocating books to all three students. But the best where the maximum books to a student is minimum of all is (3) one.



So How to solve this problem ? Should we generate some solutions ? Or should we check for a solution Like Whether is it possible to do some allocation considering some upper bound on the maximum value of books to a single student ?


Generating a solution in this type of problem is not optimal because If we do so we have to check for each possible solution  and then select the minimum and in most cases it will lead to TLE (Time Limit Exceed) because the search space is huge.



Where on the other hand we can check for a particular allocation whether it is valid or not, but still it will take O(n) to check for each allocation validity. So should we check for each possible allocation ? No, Because then it will no bad then generating all possible solutions. 



Here**Binary Search** comes into the picture. We know if our function is increasing (or decreasing) we can do binary search to find some particular value. Similarly the way we search in sorted array. Here instead of searching a value we will use binary search to find our solution.



Let me go through little about how we will apply binary search here. And also what increasing function ( not need to be strictly increasing) has to do with this If you don’t know.

![](https://02997957790365374376.googlegroups.com/attach/6dfad6658d511/Opera%20Snapshot_2020-07-13_113444_forums.autodesk.com1.png?part=0.2&view=1&vt=ANaJVrFeRljAMX-75yGfE32T4USyedqhvdgCFOIOEuoBNEb2ZM_Nao8hP_jIXEKlPJ8gEFPdHSNMp5a6xZgOU3TYPhb8-ePRXWmcCFYKwm5IBTLXNWxVny4)

See the above diagram. How I know function here is increasing ? Check for values say on some value say x1 as a upper bound on no. of books for a single student we need some p students to allocate all cartons. Then ask what would happen if decrease the x1 say x2 < x1.  Then how many students do you need on x2 more or less.



This is how we will binary search for the value x. Value x will act as an upper bound for allocation (mean we will try to allocate each student at most x books). And we will check for this value whether this is a possible solution. ( checking will run in O(n) We will see later). 



How to select value x ? . We will use some lower limit (left) and upper limit(right) of search space for x.

Now the way binary search works we will first check on mid = (left + right) / 2 . And then we will check for our allocation using the checking algorithm whether it is feasible or not. Say if the allocation requires more than k students assuming each student can’t hold any more than “x = mid” books. Then we know our search space reduces and we need to check value in a range because in this case even if we scan for a smaller value then current value = mid ( as a upper bound) we still end with having allocation which requires more than k students ( Why we can say this because the function is increasing i.e if for any x1, x2 if x1 <= x2 then prediction for f(x) is also simple f(x1) <= f(x2)).  So no need to search in that space and we reduce our search space to half and now scan only in the range where x > mid && x < right most bound. (i.e l = mid + 1)

And if this is the allocation with the exact k student then we will try to minimize it more by lowering upper bound.( r = mid - 1).



Here is the checking function step decreasing function. O(n)

![](https://02997957790365374376.googlegroups.com/attach/6dfad6658d511/Opera%20Snapshot_2020-07-13_113444_forums.autodesk.com1.png?part=0.2&view=1&vt=ANaJVrFeRljAMX-75yGfE32T4USyedqhvdgCFOIOEuoBNEb2ZM_Nao8hP_jIXEKlPJ8gEFPdHSNMp5a6xZgOU3TYPhb8-ePRXWmcCFYKwm5IBTLXNWxVny4)

What about lower limit(left) and upper limit (initial).

In the worst case if there is only one student then all cartons belong to that so we Enter cod
have allocate no more than the sum of all books in all cartons so that is the upper most limit ( at initial). And what about left, Suppose if the same no. of students as cartons then in that case the minimum books cartons is the minimum allocation that a student must get so the lower limit for search “x” is min( of all books in cartons). We can also start with lower limit = 0, It doesn’t matter.



**Checking part:**


    bool check(int mid) {
        int cnt = 1, temp = 0; // cnt indicate no. of student use in the allocation for some mid as upper_bound on no. of books per studnet
        for(int i = 0; i < n; ++i) {
            if(temp + a[i] > mid) {  // If adding a[i] increase the mid then we will start allocating next student.
                cnt++; // Thus we increase no. of student use.
                if(cnt > k) // If this exceed k (max student we have) return 0 immediately.
                    return 0;
                temp = a[i];
            }
            else 
                temp += a[i];
        }
        return 1; // If every thing above passes good then return 1.
    }

**Binary Search part:** 


    int l = mn, r = mx;
    // mn is minimum of all, mx is the sum of all books in all cartons. 
    int ans = r;
    while(l <= r) {
        int mid = (l + r) / 2; // Careful this may lead to overflown so better to use l + (r - l) / 2, or use long long int (C++)
        if(check(mid)) { // Check for mid, if it is possible then try to minimize this upper_bound on no. of books each student. 
            ans = mid; // mark this as the answer till now, since it is passing checking.
            r = mid - 1;  // reduce range to lower the upper_bound on no. of books . So in order to reduce maximum books to single
        }
        else { // else if it is not possible, mean the mid require more than k student then increase the upper bound and thus l = mid + 1
            l = mid + 1;
        }
    }


***

**Code:**

    #include <bits/stdc++.h>
    using namespace std;

    #define hey(x) cerr << #x << " is " << x << "\n";
    #define int long long int
    #define ll long long
    #define vi vector<int>
    #define vvi vector<vector<int> >
    #define vpi vector<pair<int, int> >
    #define vvpi vector<vector<pair<int, int> > >
    #define all(v) (v).begin(), (v).end()   
    #define rall(v) (v).rbegin(), (v).rend()
    #define pii pair<int, int>
    #define pb push_back
    #define SZ(x) (int)(x).size()
    #define F first
    #define S second
    #define PI 3.1415926535897932384626
    #define out cout << fixed << setprecision(12)
    #define fast ios::sync_with_stdio(false); cin.tie(0);
    #define inf 1e12

    const int N = 1e6 + 10;
    const int mod = 1e9 + 7;
    const double pi = acos(-1);

    vi a;
    int n, k;

    bool check(int mid) {
        int cnt = 1, temp = 0;
        for(int i = 0; i < n; ++i) {
            if(temp + a[i] > mid) {
                cnt++;
                if(cnt > k) 
                    return 0;
                temp = a[i];
            }
            else
                temp += a[i];
        }
        return 1;
    }

    void go() {
        cin >> n >> k;
        a = vi(n);
        int mn = inf, mx = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            mn = min(mn, a[i]);
            mx += a[i];
        }
        int l = mn, r = mx;
        int ans = r;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        vi store;
        int temp = 0;
        int cnt = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(temp + a[i] > ans) {
                store.pb(-1); // -1 used to know the pos of '/' in solution
                cnt++;
                temp = a[i];
                store.pb(a[i]);
            }
            else {
                store.pb(a[i]);
                temp += a[i];
            }
        }
        reverse(all(store));
        if(cnt > k - 1) {
            for(int i = SZ(store) - 1; i >= 0; --i) {
                if(store[i] == -1) {
                    store[i] = 0;
                    cnt--;
                    if(cnt == k - 1)
                        break;
                }
            }
        }
        for(int i = 0; i < SZ(store); ++i) {
            if(store[i]){
                if(store[i] != -1 && cnt < k - 1) {
                    if(i + 1 < SZ(store) && store[i + 1] != -1) {
                        cout << store[i] << " / ";
                        cnt++;
                    }
                    else {
                        cout << store[i] << ' ';
                    }
                }
                else if(store[i] != -1) {
                    cout << store[i] << " ";
                }
                else if(i + 1 != SZ(store)) {
                    cout << "/ ";
                }
            }
        }
        cout << '\n';
    }
        
    int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(0);

        go();
        return 0;
    }

***

# **Problem 2**

## **Here there be Dragons(IOI Training Camp, 2012)**

Since We can’t go with greedy strategy there can be various counter examples. So we will use dynamic programming.

Now we don’t know which dragon  to visit first, second, .. so on.

Because every change order will produce different ans. And we want the minimum one.


So we will compute values for each dragon if we finish the dragon j as ith ( i from 1 to k ) dragon killed but try to do it efficiently 
[not recompute already computed things].


So our dp consist of two states i, j


    Let dp[i][j] = minimum distance : if jth dragon is the ith dragon killed. 

    1 <= i <= k


So we know the value for dp[1][j] for all the dragon j. Mean we know the value for each dragon j if it is 1st dragon to killed.

It is nothing but we have to go from (0, 0) to (x[j], y[j])

So

    for(each dragon j) {
        dp[1][j] = x[j] + y[j];
    }


Now we iteratively fill the dp array for i = 2 to k .


Important point is the movement allowed : down, left and right. So no up motion is allowed and this restricts 

that if we visit dragon j as ith dragon then we can’t visit any dragon which is up in the row from dragon j.


In Fact if we analyze we can find that we need not to find dp[1][j] for all the dragon any in general any 
dp[i][j] for all the dragon j because see you can’t make every dragon to be the first dragon. 
Like suppose if you have to kill more than 1 and if you start from the last dragon as the first dragon 
to kill then you can never kill any other because you can’t take any up move.


so we can change dp[1][ j ] filling : 

d: Total dragon, k = total to kill. 




    for( int i = 1 ; i <= d - k + 1 ;++i){
        dp[1][i] = x[i] + y[i];
    }



Because if you visit d-k+2 th dragon as the 1st then  you are left with k-2 dragon available and we have to kill still k-1 so not possible. So no need to compute unnecessary.


For i = 2 to k 


    1.   for(int i = 2 ; i <= k ; ++i) {
    2.      for(int j = i ; j <= d ; ++j) {
    3.           int val = inf;
    4.           for(int p = j - 1; p >= 1; --p) {
    5.                  if(dp[i - 1][p] and temp > dist[p][j] + dp[i - 1][p])
    6.                       val = dist[p][j] + dp[i - 1][p];
    7.          }
    8.          dp[i][j] = val;
    9.        }
    10.  }




See line 2. For each dragon j if it is the ith one to visit then we have to look at the dragon which are already visited and up in row (line 4 loop is iterating backward from j ) If we current dragon is the ith one then we have to search for the one which is the i-1th. So we can know the transaction in the dp. 


To know the answers for dp[i][j] we need to look at all the dragons who are killed as the i-1 dragon. 

So find the minimum .That’s what the line 4 to 7 is doing and we fill the temp_ans to dp[i][j].


And finally what is the answer ? We must have to kill k dragon


So we iterate from dragon no. k to last dragon if it is the last dragon to kill i.e kth. dp[k][i] i from k to d.



    int ans = inf;

    for(int i = k; i <= d; ++i)
        ans = min(ans, dp[k][i]);

    cout << ans << "\n";

    Complexity: Time complexity:  O( k * d2 )  
    Space Complexity : O(k*d)

## **Code**

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
        cin >> r >> c >> k >> d;
     
        vector<pair<int, int> > a;
        a.push_back({0, 0});
        for(int i = 0; i < d; ++i){
            cin >> u >> v;
            a.push_back({u, v});
        }
        
        sort(a.begin(), a.end());

        for(int i = 1;i <= d; ++i)
            for(int j = 1;j <= d; ++j)
                if(!dist[i][j])
                    dist[i][j] = dist[j][i] = abs(a[i].first - a[j].first)+ abs(a[i].second - a[j].second);
                        
            
        for(int i = 1;i <= d - k + 1; ++i)
            dp[1][i] = a[i].first + a[i].second;
          
     
        for(int i = 2; i <= k; ++i){
            for(int j = i; j <= d; ++j){
                int val = inf;
                for(int p = j - 1; p >= 1; --p){
                        if(dp[i - 1][p] && temp > dist[p][j] + dp[i - 1][p])
                            val = dist[p][j] + dp[i - 1][p];
                }
                dp[i][j] = val;
            }
        }
        
        int ans = inf;
        for(int i = k; i <= d; ++i)
            ans = min(ans, dp[k][i]);
        
        cout << ans <<"\n";
        return 0;
    } 

***

# **Problem 3**

## **Road Trip and Museums**

**Explanation:**
We have to iterate through each connected component and during iterating 
we will keep store in a variable say sum  = the total  no. of museums  
in a connected  component. Store this sum in an array and do this for 
each connected component and when we are done with visiting all component 
Sort this array and depending upon the size of k we can select k/2 museums 
for each. For sure Lavanya will pick the k/2  with greatest value of 
no. of museums from the array and Nikhil will pick the smallest k/2 value.
If k is odd then Lavanya will pick 1 more i.e k/2 + 1 .

and if total no. of connected component is smaller than k then ans is -1.

### **Code:**

    #include <bits/stdc++.h>
    using namespace std;

    #define print(x) cerr << #x << " is " << x << endl;
    #define int long long int
    #define vi vector<int>
    #define all(v) v.begin(), v.end()
    #define pb push_back


    vector<vector<int> > g;
    vector<int> val, vis;
    int sum = 0;


    void dfs(int u) {
        if(vis[u])
            return;
        vis[u] = 1;
        sum += val[u]; // sum contain the sum of total museums in a connected component
        for(int v: g[u]) // Running through adj list
          if(!vis[v])
              dfs(v);
    }

    int32_t main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m, k;
        cin >> n >> m >> k;
        g = vector<vector<int> >(n + 1);
        val = vector<int>(n + 1);
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i = 1;i <= n; ++i)
            cin >> val[i];
        vector<int> ans;
        vis = vector<int>(n + 1,0);
        
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                sum = 0;
                dfs(i);
                ans.push_back(sum);
            }
        }
        
        sort(ans.begin(), ans.end());
        int finalAns = 0; 
        if(ans.size() < k)
            cout << "-1\n"; 
        else{
            
            // If total months are odd then : Lavanya will pick the 
            // k/2 +1 greatest value from sorted array
            // and Nikhil will pick k/2 element from starting of sorted array.
            // If n is even then both will pick k/2. Lavanya pick from end of 
            // sorted array( last k/2 max values)
            // ans Nikhil will pick k/2 from starting of sorted array 
            int n = ans.size();
            int p = k / 2;
            for(int i = 0; i < p; ++i)
                finalAns += ans[i]; // first k/2
            if(k % 2)
                p++;    
            for(int i = n - 1; i >= n - p; --i)
                finalAns += ans[i]; // last k/2 if k is even : else last k/2 + 1
            cout<<finalAns<<"\n";
        }
        return 0;
    }
