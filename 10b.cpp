#include <bits/stdc++.h>
using namespace std; 
int graph[10][10],V,dist[10][10];
void printSolution(); 

void floyd() 
{ 
	
	int  i, j, k; 

	
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	
	for (k = 0; k < V; k++) 
	{ 
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{ 
				
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	printSolution(); 
} 

void printSolution() 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == 9999) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

int main() 
{ 
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<"Enter the matrix :"<<endl;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>graph[i][j];
	floyd(); 
	return 0; 
} 
/*OUTPUT
Enter the number of vertices : 4                                                                                                             
Enter the matrix :                                                                                                                           
0 9999 3 9999                                                                                                                                
2 0 9999 9999                                                                                                                                
9999 7 0 1                                                                                                                                   
6 9999 9999 0                                                                                                                                
The following matrix shows the shortest distances between every pair of vertices                                                             
0        10      3       4                                                                                                                   
2        0       5       6                                                                                                                   
7        7       0       1                                                                                                                   
6        16      9       0
*/
