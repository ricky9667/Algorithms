#include<bits/stdc++.h>
using namespace std;

int t,n,s[10001];
int tmp,nmin,ans;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		
		cin>>n>>s[1];
		ans=s[1], nmin=s[0];
		for(int i=2;i<=n;i++)
		{
			cin>>tmp;
			s[i]=tmp+s[i-1];
			
			if(s[i]-nmin>ans)
				ans=s[i]-nmin;
			if(s[i]<nmin)
				nmin=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
