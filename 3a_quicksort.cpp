#include <bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	}
int partition(int a[],int low,int high)
{
	int pivot = a[low];
	int i=low+1;
	int j=high;
	while(1)
	{
		while(a[i]<=pivot && i<=high)
			i++;
		while(a[j]>pivot && j>=low)
			j--;
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
		else
		{
		a[low]=a[j];
		a[j]=pivot;
		}
		return j;
	}
}

void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int par=partition(a,low,high);
		quicksort(a,low,par-1);
		quicksort(a,par+1,high);		
	}
}
int main()
{
	int a[10],i,high,low,n;
	clock_t start,end;
	cout<<"Enter no of elements:";
	cin>>n;
	low=0;
	high=n-1;
	cout<<"Enter elements:";
	for(i =0;i<n;i++)
		cin>>a[i];
	start = clock();
	quicksort(a,low,high);
	end = clock();
	for(i =0;i<n;i++)
		cout<<a[i]<<endl;
	float exe = float(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution time:"<<exe<<endl;
	return 0;
}
