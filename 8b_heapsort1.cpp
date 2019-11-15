#include <iostream>
#include <limits.h>
using namespace std; 
int arr[10][10],n,k; 
int ptr[501]; 
void findSmallestRange() 
{ 
	int i,minval,maxval,minrange,minel,maxel,flag,minind; 
	for(i = 0;i <= k;i++) 
		ptr[i] = 0; 
	minrange = INT_MAX; 
	while(1)	 
	{ 
		minind = -1; 
		minval = INT_MAX; 
		maxval = INT_MIN; 
		flag = 0; 
		for(i = 0;i < k;i++) 
		{	 
				
			if(ptr[i] == n) 
			{ 
				flag = 1; 
				break; 
			} 
			
			if(ptr[i] < n && arr[i][ptr[i]] < minval) 
			{ 
				minind=i; 
				minval=arr[i][ptr[i]]; 
			} 
			
			if(ptr[i] < n && arr[i][ptr[i]] > maxval)	 
			{ 
				maxval = arr[i][ptr[i]]; 
			} 
		} 
		if(flag) 
			break; 
		ptr[minind]++; 
		if((maxval-minval) < minrange) 
		{ 
			minel = minval; 
			maxel = maxval; 
			minrange = maxel - minel; 
		} 
	} 
	cout<<"The smallest range is "<<"["<<minel<<" "<<maxel<<"]"<<endl;
}	
int main() 
{ 
	cout<<"Enter the number of lists:";
	cin>>k;
	cout<<"Enter the number of elements in each list:";
	cin>>n;
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<k;i++)
	{
	    for (int j=0;j<n;j++)
	        cin>>arr[i][j];
	}
	findSmallestRange(); 
	return 0; 
}

/*OUTPUT
Enter the number of lists:3                                                                                                                
Enter the number of elements in each list:2                                                                                                
Enter the elements:
4 7                                                                                                                     
1 2                                                                                                                                        
20 40                                                                                                                                      
The smallest range is [2 20]
*/
