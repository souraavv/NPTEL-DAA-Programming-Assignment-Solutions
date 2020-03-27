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
