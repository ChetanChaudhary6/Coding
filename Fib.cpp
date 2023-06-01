// Fibonacci in log(n)
// Easy code
// Without using matrix exponentiation
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //storing the pre-calculated value
  //what we called DP
    map<long long int,long long int>mp;
    int countStrings(long long int N) {
        // Code here
        if(N==0)return 1;
        if(N==1)return 2;
        if(N==2)return 3;
        long long int mod=1e9+7;
        long long int a=mp[N/2-1]=((mp[N/2-1])?mp[N/2-1]:countStrings(N/2-1))%mod,b=mp[N/2]=((mp[N/2])?mp[N/2]:countStrings(N/2))%mod,c=mp[N/2+1]=((mp[N/2+1])?mp[N/2+1]:countStrings(N/2+1))%mod;
        if(N%2)
        return mp[N]=((b*c%mod)-((c-b)*(b-a)%mod)+mod)%mod;
        return mp[N]=((b*b%mod)-((b-a)*(b-a)%mod)+mod)%mod;
    }
};

int main() {
    int t;
    // cin >> t;
    t=1;
    while (t--) {
        long long int N;
        cin >> N;
        if(N==0){
            cout<<"0\n";
            continue;
        }
        if(N==1){
            cout<<"1\n";
            continue;
        }
        Solution obj;
        cout << obj.countStrings(N-2) << endl;
    }
}