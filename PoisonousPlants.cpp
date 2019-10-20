#include<bits/stdc++.h>
using namespace std;

int n,ans;
vector< pair<int,int> > stk;

void print()
{
	for(int i=0;i<stk.size();i++)
		cout<<stk[i].first<<' '<<stk[i].second<<endl;
	cout<<'\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int die=0;
		pair<int,int> p;
		cin>>p.first;
		p.second=0;
		
		while(!stk.empty() && (stk.back().first>=p.first))
		{
			die=max(die,stk.back().second);
			stk.pop_back();
		}
		if(!stk.empty()) 
			p.second=die+1;
		ans=max(ans,p.second);
		stk.push_back(p);
	//	print();
	}
	cout<<ans<<endl;
	
	return 0;
}
