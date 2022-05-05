#include<bits/stdc++.h>
using namespace std;

int check_and_get_num_parts(vector<int>& v, int mid, int& p, int flag = 0){
    int curr = 0, cnt = 0;
    int n = v.size();
    for(int i = n-1; i >= 0; i--){
        if(v[i] > mid) return 0;
        if(curr + v[i] > mid){
            cnt++;
            curr = v[i];
        }
        else curr += v[i];
    }
    return flag ? cnt + 1 <= p : cnt + 1;
}


int getRes(vector<int>& v, int& n, int l, int r, int& p){
    while(l < r){
        int mid =  l + (r-l) / 2;
        if(check_and_get_num_parts(v, mid, p, 1)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    int sum = 0, mn = INT_MAX;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i: v){
        sum += i;
        mn = min(mn, i);
    } 
    int val = getRes(v, n, mn, sum, p);
    int curr = 0;
    unordered_map<int, int> mp;
    for(int i = n-1; i >= 0; i--){
        if(curr + v[i] > val){
            mp[i]++;
            curr = v[i];
        }
        else curr += v[i];
    }
    int num = check_and_get_num_parts(v, val, p);
    for(int i = 0; i < n-1 && num < p; i++){
        if(mp.find(i) == mp.end()){
            mp[i]++;
            num++;
        }
    }
    for(int i = 0; i < n; i++){
        if(mp.find(i) != mp.end()){
            cout<<v[i]<<" / ";
        }
        else cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}