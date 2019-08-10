#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the value of n:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int m=-999;
	for(int i=0;i<n;i++)
	{
		if(a[i]>m)
			m=a[i];
	}
	cout<<"Maximum : "<<m<<"\n";
	return 0;
}
