#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	int n,temp,k,min;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the value of k :";
	cin>>k;
	clock_t start,end;
	start=clock();
	for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[min])
            min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
	cout<<"The sorted array is:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl<<"The "<<k<<" largest array elements are :";
	for(int i=0;i<k;i++)
		cout<<a[i]<<" ";
	end=clock();
	double t=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<endl<<"Time taken : "<<t<<;
	return 0;
}
