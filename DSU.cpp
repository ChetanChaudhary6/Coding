// Disjoint Union Set
//Helpful for connected components and detect cycle
//Minimum Spanning Tree -> Kruskal's Algorithm
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int INF=1e5;
vector<int>parent(INF),size(INF);
//initialize the parent array and size array
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
//find the parent of the element
// and do path compression also
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
// merge two sets using their size paremeter
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

signed main()
{
    for(int i=0;i<5;i++)make_set(i);
    union_sets(3,2);
    union_sets(2,1);
    cout<<parent[1];
    return 0;
}