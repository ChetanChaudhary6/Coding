#include<bits/stdc++.h>
using namespace std;
#define int long long int


//topological sort using dfs and stack
//done in directed acyclic graph
//kahn's algorithm can be used

void toposort(int node, vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &s){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it.first]){
            toposort(it.first,adj,vis,s);
        }
    }
    s.push(node);
}

//we can find shortest path in directed acyclic graph using topological sort
//o(n+m) time complexity better than dijsktra's algorithm
//because we already calculated minimum path when we move as it is directed

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    vector<pair<int,int>> adj[n];
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        adj[u].push_back({v,weight});
    }
    vector<int> dist(n,-1);
    dist[0]=0;
    vector<int> vis(n,0);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,vis,s);
        }
    }
    while(!s.empty()){
        int node = s.top();
        s.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node]==-1&&v){
                dist[v] = -1;
                continue;
            }
            if(dist[v]==-1){
                dist[v] = dist[node]+ wt;
            }else if (dist[v] != -1) {
                if(dist[node]+wt < dist[v]){
                    dist[v] = dist[node]+wt;
                }
            }
        }
    }
    return dist;
} 
signed main()
{
    
    return 0;
}