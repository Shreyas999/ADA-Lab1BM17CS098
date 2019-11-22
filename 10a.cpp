#include<bits/stdc++.h>
using namespace std;  
int graph[10][10] ,V;  
int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
int printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
void dijkstra(int src) 
{ 
    int dist[V];
  
    bool sptSet[V];
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
     dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet); 
  
         sptSet[u] = true; 
  
        for (int v = 0; v < V; v++) 
  
           if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    printSolution(dist); 
} 
  
int main() 
{ 
    
    cout<<"Enter the number of vertices : ";
    cin>>V;
    int s;
    for (int i=0;i<V;i++)
    {
        for (int j=0;j<V;j++)
            cin>>graph[i][j];
    }
    cout<<"Enter source:";
    cin>>s;
    dijkstra( s); 
    return 0; 
}

/*OUTPUT
Enter the number of vertices : 5                                                                                                             
0 3 0 7 0                                                                                                                                    
3 0 4 2 0                                                                                                                                    
0 4 0 5 6                                                                                                                                    
7 2 5 0 4                                                                                                                                    
0 0 6 4 0                                                                                                                                    
Enter source:0                                                                                                                               
Vertex           Distance from Source                                                                                                        
0                0                                                                                                                           
1                3                                                                                                                           
2                7                                                                                                                           
3                5                                                                                                                           
4                9
*/
