#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
//bfs means level order traversal
//effective in finding shortest path
//at a time we have two levels in queue
vector<vector<int>>graph; 
vector<int>visited;
//bfs on graph and tree
void bfs_graph(int node){
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while (!q.empty())
    {
        int currnode=q.front();
        q.pop();
        for(auto i:graph[currnode]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
}
//useful for single level in queue or all nodes at same height
//easy to handle using size of queue
void bfs_graph_size(int node){
    queue<int>q;
    visited[node]=1;
    q.push(node);
    while (!q.empty())
    {
        int size=q.size(),sz=size;//keep track of no of nodes in a level
        while (size)
        {
            int currnode=q.front();
            q.pop();
            for(auto i:graph[currnode]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
            size--;
        }
        
    }
    
}
//bfs on binary tree
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
void bfs_btree(Node*root){
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        root=q.front();
        q.pop();
        q.push(root->left);
        q.push(root->right);
    }
    
}
//for size part
void bfs_btree_size(Node*root){
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        while (size)
        {
            root=q.front();
            q.pop();
            q.push(root->left);
            q.push(root->right);
            size--;
        }
    }
    
}
signed main()
{
    //we will run bfs from source node 1
    bfs_graph(1);
    return 0;
}
