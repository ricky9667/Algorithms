#include<bits/stdc++.h>
using namespace std;

int t,dp[1005][1005];
string m,b;

int lcs(int x,int y)
{
	if(!x || !y) return dp[x][y]=0;
	if(dp[x][y]) return dp[x][y];
	if(m[x]==b[y])
		return dp[x][y]=lcs(x-1,y-1)+1;
	else
		return dp[x][y]=max(lcs(x-1,y),lcs(x,y-1));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin>>m>>b>>t;
	m.insert(m.begin(),'$');
	b.insert(b.begin(),'$');
	
	cout<<lcs(m.size(),b.size());
	
	return 0;
}
