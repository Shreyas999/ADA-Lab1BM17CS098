#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number:";
	cin>>n;
	clock_t start,end;
	int s=0,e=n,ans,mid;
	start=clock();
	{
	while(s<=e)
	{
		mid=(s+e)/2;
		if(mid*mid==n)
		{
			ans=mid;
			break;
		}
		else if(mid*mid<n)
		{	s=mid+1;
			ans=mid;
		}
		else
			e=mid-1;
	}
	}
	end=clock();
	cout<<ans<<endl;
	double t=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<"Time :"<<t*1000<<endl;
}
