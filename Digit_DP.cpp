/*
RETURN NO OF INTEGERS BETWEEN RANGE (L,R)
SATISFY THE PROPERTY THAT ITS DIGIT SUM IS BETWEEN (MIN_SUM,MAX_SUM)
*/
//WE CAN USE DIGIT DP IF WE ARE DOING OPERATION RELATED TO DIGITS
//LIKE FOR FINDING NO OF INTEGERS IN A RANGE
//AND WE DO SPECIFIC OPERATION ON DIGITS -> HERE WE FIND SUM I.E. FUN(DIGITS)
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
//FUN FOR HANDLING CASE LIKE 575279075
//AS DP CALCULATES ONLY 9999999 THING
int fun(vector<vector<int>>&dp,string s,int min_sum,int max_sum){
    int ans=0,cur=0;
    for(int a=0;a<s.size();a++){
        int n=s[a]-'0';
        for(int j=0;j<=max_sum;j++){
            for(int d=0;d<n;d++){
                int sum=j+d+cur;
                if(min_sum<=sum&&sum<=max_sum)ans=(ans+dp[s.size()-a-1][j])%mod;
            }
        }
        cur+=n;
    }
    return ans;
}
//FUN FOR MAKING DP
//DP[I][SUM]
//AS DP[I][SUM] DEPENDS ON ALL PREVIOUS SUM
//AND THEN IT CAN ADD UP TO DIFFERENT SUM USING(0-9)
void DP(vector<vector<int>>&dp,string s,int max_sum){
    for(int i=1;i<s.size();i++){
        for(int j=0;j<=max_sum;j++){
            for(int d=0;d<=9;d++){
                int sum=j+d;
                if(sum<=max_sum)dp[i][sum]=(dp[i][sum]+dp[i-1][j])%mod;
            }
        }
    }
}
//RETURN COUNT OF NUMBERS
int count(string num1, string num2, int min_sum, int max_sum) {
    vector<vector<int>>dpmin_sum(num1.size(),vector<int>(max_sum+1,0)),dpmax_sum(num2.size(),vector<int>(max_sum+1,0));
    dpmin_sum[0][0]=1;
    dpmax_sum[0][0]=1;
    DP(dpmin_sum,num1,max_sum);
    DP(dpmax_sum,num2,max_sum);
    int ans1=fun(dpmin_sum,num1,min_sum,max_sum),ans2=fun(dpmax_sum,num2,min_sum,max_sum);
    int o=0;
    for(auto i:num2)o+=i-'0';
    if(min_sum<=o&&o<=max_sum)return (ans2+mod+1-ans1)%mod;
    return (ans2+mod-ans1)%mod;
}

int main(){
    string num1="1",num2="5";
    int min_sum=1,max_sum=5;
    cout<<count(num1,num2,min_sum,max_sum);
}