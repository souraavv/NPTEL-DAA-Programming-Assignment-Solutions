
#include<bits/stdc++.h>
#define ul unsigned long
#define ll long long
#define repeat(i,a,b) for(int i = a;i<b;++i)
#define for2(i,b) for(int i = b;i>=0;--i)
using namespace std;
ll positive(ll i) {
	if (i < 0) return 0;
	else return i;
}
int main()
{
	ll h, n, c;
	cin >> h >> n >> c;
	vector<pair<ll, ll>> vc;
	repeat(i,0,n) {
		ll hours, rupee;
		cin >> hours >> rupee;
		vc.push_back({hours,rupee});
	}
	vc.push_back({h,-1});
	ll cost = 0, store = 0;
	repeat(i,0,n)
	{
		ll minIndex = -1;
		ll curIndex = i + 1;
		if(i!=0)
		store -= (vc[i].first - vc[i - 1].first);
		while ( curIndex <=n && vc[i].first +c >= vc[curIndex].first) 
		{
			if (vc[i].second> vc[curIndex].second) 
			{
				minIndex = curIndex;
				break;
			}
			curIndex++;
		}
		ll dist;
		if (minIndex == -1) 
		{
			dist = c - store;
		}
		else 
		{
			dist = vc[curIndex].first - vc[i].first - store;
		}
		dist = positive(dist);
		store += dist;
		cost += (dist*vc[i].second);
	}
	cout << cost <<endl;
	return 0;
}
