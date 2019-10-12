#include<bits/stdc++.h>
using namespace std;
int max(int a,int b) 
{
	return(a>b)?a:b;
} 

void knapsack(int W,int wt[],int val[],int n) 
{ 
	int i, w; 
	int K[n+1][W+1]; 
	for (i=0;i<=n;i++) 
	{ 
	for (w=0;w<=W;w++) 
	{ 
	   if (i==0 || w==0) 
	   	K[i][w] = 0; 
	   else if (wt[i-1]<= w) 
		K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]); 
	   else
		K[i][w]=K[i-1][w]; 
	} 
	} 
	int res=K[n][W];
	cout<<"Maximum Profit :"<<res<<endl;
	w=W;
	cout<<"Items and Weights:"<<endl;
	for (i=n;i>0 && res>0;i--)  
	{    
		if (res==K[i-1][w])  
		    continue;         
		else 
		{
		    cout<<i<<" "<<wt[i-1]<<endl;
		    res = res-val[i-1]; 
		    w=w-wt[i-1]; 
		} 
    	} 
} 
  
int main() 
{ 
	int val[10]; 
	int wt[10]; 
	int W; 
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	cout<<"Enter the weight:";
	cin>>W;
	cout<<"Enter the values:";
	for(int i=0;i<n;i++)
		cin>>val[i];
	cout<<"Enter the weights:";
	for(int i=0;i<n;i++)
		cin>>wt[i];
	knapsack(W,wt,val,n);
	return 0; 
}

/*OUTPUT
Enter the number of elements:5
Enter the weight:6
Enter the values:25 20 15 40 50 
Enter the weights:3 2 1 4 5
Maximum Profit :65
Items and Weights:
5 5
3 1
*/
