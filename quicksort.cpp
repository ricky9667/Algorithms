#include<bits/stdc++.h>
using namespace std;

int n,a[100000],b;

void output()
{
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	puts("");
}

int partition(int l,int r)
{
//	printf("\tp(%d,%d)=",l,r);
	int i=l-1,j=l;
	while(j<=r)
	{
		if(a[j]<=a[r])
			swap(a[++i],a[j]);
		j++;
	}
//	printf("p=%d\n",i);
//	output();
	return i;
}

void quicksort(int l,int r) // 3 1 5 2 4 
{
//	printf("q(%d,%d)\n",l,r);
	if(l<r)
	{
		int p=partition(l,r);
		quicksort(l,p-1);
		quicksort(p+1,r);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	quicksort(1,n);
	output();
	return 0;
}
