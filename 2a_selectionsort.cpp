#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    int n,i,j,k,temp,mini,mindex;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elements :";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the value of k:";
    cin>>k;
    clock_t start,end;
    start=clock();
    for(i=0;i<k;i++)
    {
        mindex=i;;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mindex])
                mindex=j;
        }
        temp=a[mindex];
        a[mindex]=a[i];
        a[i]=temp;
    }
    end=clock();
    cout<<"Sorted array is:";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"The "<<k<<"th smallest element is :"<<a[k-1];
    double t=double(end-start)/double(CLOCKS_PER_SEC);
	cout<<endl<<"Time taken : "<<t;
	return 0;
}
