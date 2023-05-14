#include<bits/stdc++.h>
using namespace std;
#define int long long int

//depth first search
vector<vector<int>>graph;
vector<int>visited;
//dfs on tree and graph
void dfs(int vertex){
    //entering in a vertex
    visited[vertex]=1;
    for(auto child:graph[vertex]){
        if(!visited[child]){
            //tends to entering in the child
            dfs(child);
            //returning from child
        }
    }
    //returning from vertex
}
//dfs on binary tree
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
void dfs_btree(Node*vertex){
    //entering in a vertex
    //tends to entering in the child
    dfs_btree(vertex->left);
    dfs_btree(vertex->right);
    //returning from child
    //returning from vertex
}
signed main()
{
    dfs(1);
    return 0;
}