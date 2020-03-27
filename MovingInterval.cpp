/*

Moving Intervals
Zonal Computing Olympiad 2018

There are C cakes in a row, numbered from 1 to C. There are N children, each of whom have selected a consecutive set of cakes to eat. That is, Child i has decided to eat all the cakes from Si to Ei, end points inclusive. If there is a cake which appears in some two childrens' set, then they will fight because both of them want to eat that cake, and you don't want that to happen.

You will be given an integer K which will be either 0 or 1. If K is 0, then you should find out if some two children will fight. Print "Good" if no one fights, and "Bad" if someone fights.

If K is 1, then you can persuade at most one child to change his decision to some other set of cakes. But the number of cakes that he eats must be the same. That is, if Child i had initially decided that he wants to eat the cakes from Si to Ei, then you could persuade the child to instead eat the cakes from X to Y instead, for any valid X and Y (ie. 1 ≤ X ≤ Y ≤ C), provided that the number of cakes is the same (ie. Ei - Si + 1 = Y - X + 1). If after persuading at most 1 Child to change his decision, no fights happen, then print "Good". But if no matter what you do, someone will fight, then print "Bad".

Solution hint
Sort the intervals and check for overlaps.

Input format
The first line of each test case contains three integers C, N and K denoting the number of cakes, number of children and K, respectively.

The i-th of the next N lines contains two space separated integers Si and Ei which denotes the initial decision of Child i. That is, Child i wants to eat from cake Si to cake Ei.

Output format
For each test case, output a single line containing "Good" or "Bad".

Constraints
1 ≤ T ≤ 10
1 ≤ C ≤ 109
1 ≤ N ≤ 105
0 ≤ K ≤ 1
1 ≤ Si, Ei ≤ C

Sample input 1
5 2 0
2 2
3 5
Sample output 1
Good

Sample input 2
5 2 1
2 2
2 5
Sample output 2
Good

Sample input 3
5 2 1
2 3
2 5
Sample output 3
Bad

Explanation
Sample 1: Child 1 wants to eat the second cake, and Child 2 wants to eat Cakes 3, 4 and 5. So there is no fight, and the answer is "Good".

Sample 2: Child 1 wants to eat Cake 2, and Child 2 wants to eat Cakes 2, 3, 4 and 5. Both of them want to eat Cake 2, and hence it could lead to a fight. But because K = 1, we can persuade one of the children to change their decision. For instance, we could persuade Child 1 to change his decision from [2, 2] to [1, 1]. After this, there is no fight, and the hence answer is "Good".

Sample 3: Child 1 wants to eat Cake 2 and Cake 3, and Child 2 wants to eat Cakes 2, 3, 4 and 5. Both of them want to eat Cakes 2 and 3, and hence it could lead to a fight. And because K = 1, we can persuade one of the children to change their decision. For instance, we could persuade Child 1 to change his decision from [2, 3] to [1, 2]. But even after this, both of them want to eat Cake 2. You can verify that no matter how we persuade at most 1 child, they will end up fighting. Hence the answer is "Bad".


*/



#include<bits/stdc++.h>
using namespace std;

#define int long long int 


int32_t main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,k;
    cin>>c>>n>>k;
    vector<pair<int,int> >v;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    if(k==0){
        int cnt=0;
        for(int i=0;i<v.size()-1;++i){
            for(int j=i+1;j<v.size();++j){
                if(v[i].second<v[j].first)break;
                cnt++;   
            }
        }
        if(cnt)cout<<"Bad\n";
        else cout<<"Good\n";
    }   
    else{
        vector<int> gap;
        
        gap.push_back(v[0].first-2);
        gap.push_back(c-(v[v.size()-1].second+1));
        
        for(int i=0;i<v.size()-1;++i){
            gap.push_back(v[i+1].first-v[i].second-1);
        }
        
        
        int cnt=0;
        vector<int> bad;
        for(int i=0;i<v.size()-1;++i){
            for(int j=i+1;j<v.size();++j){
                if(v[i].second<v[j].first)break;
                else{
                    bad.push_back(v[i].second-v[i].first);
                    cnt++;
                    break;
                }
            }
        }
        
        
        if(cnt==0){
            cout<<"Good\n";
            return 0;
        }
        
        if(bad.size()>1){
            cout<<"Bad\n";
        }
        else{
            int a=bad[0];
            for(int i: gap){
                if(i>=a){
                    cout<<"Good\n";
                    return 0;
                }
            }
            cout<<"Bad\n";
        }
    }
    return 0;
}
