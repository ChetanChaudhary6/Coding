#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//policy based data structures
//useful in finding index of element in set

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
// template<typename T> 
// using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
//template<class key, class value, class cmp = std::less<key>>
//using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
    
    //find_by_order(k)  returns iterator to kth element starting from 0;
    //order_of_key(k) returns count of elements strictly smaller than k;

int getInversions(int *arr, int n){
    // Write your code here.
    ordered_set<int> os;
    os.insert(arr[n-1]);
    int c=0;
    for(int i=n-2;i>=0;i--){
        c+=os.order_of_key(arr[i]);
        os.insert(arr[i]);
    }
    return c;
}

signed main(){
    int n=5;
    int arr[5]={2, 5 ,1, 3 ,4};
    cout<<getInversions(arr,n);
}