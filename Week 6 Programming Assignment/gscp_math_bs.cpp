/*
Getting Started with cp:

Swayam wants to play a game with you. He has an integer with him, S, but he has hid it from you. Instead, he has shared some information about S.

In particular, for every i such that 1 ≤ i ≤ N, he has told you the value ⌊(i*S)/K⌋. This is given to you as the array A1, A2, ..., AN, where Ai = ⌊(i*S)/K⌋. He has also told you the value of K. But since he has not shared the value of S, you want to find the largest possible range [L,R] in which S could lie. That is, find the largest possible range [L,R] such that, for any integer P ∈ [L,R], Ai is equal to ⌊(i*P)/K⌋ for all i.

It is guaranteed that such a range always exists and is unique. You may read the sample test cases for more clarity.

Note that ⌊x⌋ denotes floor(x), which is largest integer which is ≤ x.

Input
The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains two space-separated integers N and K respectively.
The second line of each test case contains N space separated integers, A1, A2, ..., AN.
Output
For each testcase, print a single line containing two space separated integers L and R respectively.
Constraints
1 ≤ T ≤ 103
1 ≤ N ≤ 105
1 ≤ K ≤ 109
0 ≤ Ai ≤ 1.1*1017, for all possible values of i.
It is guaranteed that Ai*K doesn't exceed 1.1*1017
It is guaranteed that 0 ≤ S ≤ 1.1*1012
Sum of N over all test cases doesn't exceed 5*105
Example Input
4
5 10
2 4 6 9 11
5 100
0 0 0 0 1
3 1
111111111111 222222222222 333333333333
2 100
10000000000 20000000000
Example Output
23 23
20 24
111111111111 111111111111
1000000000000 1000000000049

*/

// My solution : 

#include <bits/stdc++.h>
using namespace std;

#define int long int

void go() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int left, right;
    
    auto check = [&](int mid) {
        for (int i = 1; i <= n; ++i) {
            int curVal = (i * mid) / k;
            if (curVal < a[i - 1]) {
                return -1;
            } else if (curVal > a[i - 1]) {
                return 1;
            }
        }
        return 0;
    };
    
  	auto findL = [&] () {
  	    int l = 0, r = 1e13;
  	    int lower = r;
  	    while (l <= r) {
  	        int mid = (l + r) / 2;
  	        int ret = check(mid);
  	        if (ret == 0) {
  	            lower = min(lower, mid);
  	            r = mid - 1;
  	        }
  	        else if (ret > 0) {
  	            r = mid - 1;
  	        }
  	        else {
  	            l = mid + 1;
  	        }
  	    }
  		return lower;
    };
    
    auto findR = [&] () {
  	    int l = 0, r = 1e13;
  	    int upper = l;
  	    while (l <= r) {
  	        int mid = (l + r) / 2;
  	        int ret = check(mid);
  	        if (ret == 0) {
  	            upper = max(upper, mid);
  	            l = mid + 1;
  	        }
  	        else if (ret > 0) {
  	            r = mid - 1;
  	        }
  	        else {
  	            l = mid + 1;
  	        }
  	    }
  		return upper;
    };
    
    cout << findL() << ' ' << findR() << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        go();
    }
    return 0;
}


// Provided by Instructor 
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int main()
{
    ll t,n,k,i,j,l,r,tmp,div;

    cin >> t;
    assert(t>0 && t<=10000);
    while(t--){
        cin >>n >> div;
        assert(n>0 && n<=100000);
        assert(div>0 && div<=1000000000);
        ll a[n];
        l=0;
        r=LLONG_MAX;

        for(i=0;i<n;i++){
            cin >> a[i];
            j=a[i]*div;
            k=(a[i]+1)*div-1;

            tmp=j/(i+1);
            if(j%(i+1))
                tmp++;

            if(tmp>l)
                l=tmp;

            if(k/(i+1)<r)
                r=k/(i+1);
        }
        cout << l << " " << r << "\n";
    }
	return 0;
}
