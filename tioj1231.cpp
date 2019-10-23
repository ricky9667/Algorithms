#include<bits/stdc++.h>
using namespace std;

struct type{
	pair<int,int> p;
	bool operator< (const type &a)const {
		return p.first>a.p.first;
	}
} food[100001];
priority_queue<type> pq;
int n,d,ptr,ans;

bool cmp(type x,type y)
{
	if(x.p.second==y.p.second)
		return x.p.first<y.p.first;
	return x.p.second<y.p.second;
}

int main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>food[i].p.first>>food[i].p.second;
	cin>>d;
	ptr=0,ans=0;
	
	sort(food,food+n,cmp);
	for(int i=1;i<=d;i++)
	{
	//	cout<<"d = "<<i<<':'<<endl; // test code
	//	cout<<" ptr = "<<ptr<<endl; // test code
		while(food[ptr].p.second<=i && ptr<n)
		{
		//	cout<<"  push "<<food[ptr].p.first<<' '<<food[ptr].p.second<<endl;
			pq.push(food[ptr++]);
		}	// test code
			
		while(pq.size()>i)
		{
		//	cout<<"  pop "<<pq.top().p.first<<' '<<pq.top().p.second<<endl;
			pq.pop();
		}	// test code
			
	//	cout<<"\n"; // test code
	}
	while(ptr<n)
		pq.push(food[ptr++]);
	while(pq.size()>d)
		pq.pop();
		
	if(pq.size()<d) 
		ans-=(d-pq.size());
	while(!pq.empty())
	{
		ans+=pq.top().p.first;
		pq.pop();
	}
	cout<<ans<<endl;
	return 0;
}
