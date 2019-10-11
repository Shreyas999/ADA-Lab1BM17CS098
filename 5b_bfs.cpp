#include<bits/stdc++.h>
using namespace std;
int adj[10][10],n,v[10];
void input(){
    cout<<"Enter the number of nodes:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    cout<<"Enter adjacent matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
}
void BFS(int k){
    queue <int> q;
    v[k-1]=1;
    cout<<"Graph Traversal:";
    cout<<"\n"<<k;
    q.push(k-1);
    while(!q.empty()){
        int f= q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(adj[f][i]==1){
                if(v[i]==0){
                    q.push(i);
                    v[i]=1;
                    cout<<" "<<i+1;
                }
            }
        }
    }
}
int main(){
    input();
    int start;
    cout<<"Enter the source vertex:\n";
    cin>>start;
    BFS(start);
}

/*OUTPUT
Enter the number of nodes:
4
Enter adjacent matrix:
1 1 1 0
1 0 0 0
1 1 1 0
0 0 0 1
Enter the source vertex:
3
Graph Traversal:
3 1 2
*/
