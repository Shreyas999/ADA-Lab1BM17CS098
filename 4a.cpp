#include<bits/stdc++.h>
using namespace std;
int G[10][10],visited[10],n;
void DFS(int i)
{
int j;
visited[i]=1;
for(j=0;j<n;j++)
{
if(!visited[j] && G[i][j]==1){
cout<<endl<<i<<"->"<<j;
DFS(j);
}}
}
int main()
{
int i,j;
clock_t start,end;
cout<<"Enter number of vertices:";
cin>>n;
cout<<"\nEnter adjecency matrix of the graph:\n";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>G[i][j];
for(i=0;i<n;i++)
visited[i]=0;
start = clock();
DFS(0);
end = clock();
float exe = float(end - start)/CLOCKS_PER_SEC;
cout<<"\nExecution:"<<exe;
return 0;
}
