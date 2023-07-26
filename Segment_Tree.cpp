//for finding queries in a range
//work if operator follows associative property
/*lazy propagation for updates in a range
do updates where necessary
else see it in direct query
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
int t[4*100000]; 

void build(vector<int>&a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n,0);
        for(auto &i:v)cin>>i;
        build(v,1,0,n-1);
        int q;
        cin>>q;
        while (q--)
        {
            int a,x,y;
            cin>>a>>x>>y;
            if(a)cout<<sum(1,0,n-1,x-1,y-1)<<"\n";
            else update(1,0,n-1,x-1,y);
        }
    }
    return 0;
}