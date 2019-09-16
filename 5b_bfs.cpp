#include<bits/stdc++.h>
using namespace std;
int adj[10][10],n,v[10];
void input(){
    cout<<"Enter the number of nodes:";
    cin>>n;
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
}
void BFS(int k){
    queue <int> q;
    v[k]=1;
    cout<<k<<" ";
    q.push(k);
    while(!q.empty()){
        int f= q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(adj[f][i]==1){
                if(v[i]==0){
                    q.push(i);
                    v[i]=1;
                    cout<<i<<" ";
                }
            }
        }
    }
}
int main(){
    input();
    int start;
    cout<<"Enter the source vertex:";
    cin>>start;
    BFS(start);
}
