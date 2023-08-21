#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
bool isValid(int i,int j,int n,int m){
    return (i>=0)&&(j>=0)&&(i<n)&&(j<m);
}
//minimum time required to reach from 0,0 to n-1,m-1 
//where distance is measured using maximum absolute value of valid path
int minimumTimeTakingPath(vector<vector<int>> &heights)
{
    int n=heights.size(),m=heights[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e6));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{n-1,m-1}});
    dist[n-1][m-1]=0;
    while(!pq.empty()){
        auto node=pq.top();
        int x=node.second.first;
        int y=node.second.second;
        pq.pop();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int ii=0;ii<4;ii++){
            int i=dx[ii]+x;
            int j=dy[ii]+y;
            if(isValid(i,j,n,m)&&dist[i][j]>max(dist[x][y],abs(heights[i][j]-heights[x][y]))){
                dist[i][j]=max(dist[x][y],abs(heights[i][j]-heights[x][y]));
                pq.push({dist[i][j],{i,j}});
            }
        }
    }
    return dist[0][0];
}

signed main()
{
    vector<vector<int>>heights;
    return 0;
}