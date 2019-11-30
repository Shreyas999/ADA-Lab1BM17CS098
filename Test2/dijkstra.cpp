#include<bits/stdc++.h>
using namespace std;
int n;
int dijkstra(int c[][],int src)
{
int dist[20];
bool vis[20];
int count=0,min,u;
for(int j=0;j<n;j++)
{
dist[j]=c[src][j];
}
for(int j=0;j<n;j++)
{
vis[j]=false;
}
dist[src]=0;
vis[src]=true;
count=1;
while(count!=(n-1))
{
min = INT_MAX;
for(int j=0;j<n;j++)
{
if((dist[j]<min)&&(!vis[j]))
{
min=dist[j];
u=j;
}
}
vis[u]=true;
count+=1;
for(int j=0;j<n;j++)
{
if((min+c[u][j])<dist[j] && (!vis[j]))
{
dist[j]=min+c[u][j];
}
}
}c
out<<"The shortest distance are : "<<endl;
for(int j=0;j<n;j++)
{
cout<<src<<" -> "<<j<<" = "<<dist[j]<<endl;
}
return 0;
} int main()
{
int adjmat[20][20];
int src;
cout<<"Enter the number of vertices : ";
cin>>n;
cout<<n<<endl;
cout<<"Enter the adjacency matrix : "<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>adjmat[i][j];
cout<<adjmat[i][j]<<" ";
} cout<<endl;
}c
out<<"Enter the source vertex : ";
cin>>src;
cout<<src<<endl;
dijkstra(adjmat,src);
}
