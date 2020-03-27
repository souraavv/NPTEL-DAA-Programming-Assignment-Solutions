/*

Book cartons

A university department is shifting its department library to a more spacious room on a newly constructed floor. The books from the library have been packed into m cartons, numbered 1, 2, …, m, containing b1, b2, …, bm books, respectively, and transported to the new library room.

There are k student volunteers available to unpack the m cartons, where k ≤ m. Each carton must be assigned to a single volunteer, and every volunteer must get a non-empty continuous sequence of cartons to unpack.

More formally, we need to find numbers 0 = c0 < c1 < c2 < … < ck = m such that volunteer j, 1 ≤ j ≤ k unpacks cartons cj-1+1 to cj.

The time each volunteer takes to unpack a carton is directly proportional to the number of books in the carton. The goal is parallelize the unpacking to finish in the fastest possible time. For this, we need to assign cartons such that the maximum number of books assigned to any one volunteer is minimized.

Solution hint
Given a target T, use a greedy strategy to check if there is a legal allocation where no volunteer is assigned more than T books. Find the optimum T using binary search. Note that if a greedy strategy finds an allocation achieving target T using k' < k volunteers, this allocation can always be subdivided to achieve the same target with exactly k volunteers.

Input format
Each test case consists of exactly two lines. The first line has are two integers m and k. The second line has m integers b1, b2, …, bm separated by spaces.

Output format
Your output should be a single line with the input sequence b1, b2, …, bm divided into exactly k parts such that the maximum sum in a single part is as small as possible. Use the slash character ('/') to separate the parts. There must be exactly one space character between any two successive numbers and between the number and the slash. If there is more than one solution, print the one that minimizes the work assigned to the first volunteer, then to the second volunteer etc. Each volunteer must be assigned at least one carton.

Test Data:
You may assume that 1 ≤ k ≤ m ≤ 500, always. Also, each carton contains a positive number of books, which is less than 10,000,000.

Sample Input 1:
9 3
100 200 300 400 500 600 700 800 900
Sample Output 1:
100 200 300 400 500 / 600 700 / 800 900

Sample Input 2:
5 4
100 100 100 100 100
Sample Output 2:
100 / 100 / 100 / 100 100


*/

#include <bits/stdc++.h>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

vi a;
int n,k;

int fans=0;

bool check(int m){
    int temp=0;
    int val=1;
    for(int i=0;i<n;++i){
        if(temp+a[i]>m){
            temp=a[i];
            val++;
            if(val>k)return false;
        }
        else temp+=a[i];
    }
    return true;
}

int go(int l,int r){
    
    while(l<=r){
        int mid=(r+l)/2;
        if(check(mid)){
            fans=mid;
            r=mid-1;
        }
        else 
            l=mid+1;
    }
    return fans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    
    a=vi(n);
  
    int sum=0;
    int mx=LLONG_MIN;
    int mn=LLONG_MAX;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }

    if(mx==mn){
     
        if(k==1){
            for(int i: a)cout<<i<<" ";
            cout<<"\n";
            return 0;
        }
      
        int ans=go(0,sum);
       
        int p=ans/mn;
        
        int n1=n-p;
        int k1=k-1;

        
        int sz=n1/k1;
        int rem=n1%k1;
       
      int srem=rem;
      int cnt=rem&1?1:0;
      while(rem+sz>p){
        rem/=2;
        cnt++;
      }
      
      srem=rem;
       // cout<<sz*k1<<" "<<rem<<"\n";
        int i;
        
        for(i=0;i<(k1-cnt-1)*sz;i+=sz){
            for(int j=i;j<i+sz;++j){
                cout<<a[j]<<" ";
            }
            cout<<"/ ";
        }
      	
        int j;
      	int cnt2=0;
        for(j=i;j<n-p;++j){
            cout<<a[j]<<" ";
          	cnt2++;
          if(cnt2==sz+rem){
           	cnt2=0;
            cout<<"/ ";
          }
        }
       
        
        for(int i=n-p;i<n;++i){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
      
        return 0;
    } 
    fans=mx;
    int ans=go(mx,sum);
    
 
    int temp=0;
    int cnt=0;
    int i;
    for(i=0;i<n;++i){
        if(cnt==k-1)break;
        if(temp+a[i]>ans){
            cnt++;
            cout<<"/ ";
            temp=a[i];
            cout<<a[i]<<" ";
        }
        else {
            temp+=a[i];
            cout<<a[i]<<" ";
        }
    }
    for(int j=i;j<n-1;++j)cout<<a[j]<<" ";
    cout<<a[n-1]<<"\n";
    return 0;
} 
