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
-- Solution -- 

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
    hey(mid);
    int cnt = 1;
    int temp = 0;
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
            ans = min(ans, mid);
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
            store.pb(-1);
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
    cout << "\n";
}
    
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    go();
    return 0;
}
