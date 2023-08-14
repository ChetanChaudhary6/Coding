#include<bits/stdc++.h>
using namespace std;
#define int long long int
 //https://atcoder.jp/contests/agc060/tasks/agc060_a
 /*
 here dp state depends on previous two state
 a type of dp
 like find possible ways to insert any number in place of -1 or ?
 */
signed main()
{
    int n,mod=998244353;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(26,vector<int>(26,0)));
    if(s[0]!='?'&&s[1]!='?')dp[1][s[0]-'a'][s[1]-'a']=1;
    else if(s[0]=='?'&&s[1]!='?'){for(int i=0;i<26;i++){if(i!=s[1]-'a')dp[1][i][s[1]-'a']=1;}}
    else if(s[0]!='?'&&s[1]=='?'){for(int i=0;i<26;i++){if(i!=s[0]-'a')dp[1][s[0]-'a'][i]=1;}}
    else {for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(j!=i)dp[1][i][j]=1;}
    int ans=0;
    for (int i = 2; i < n; i++)
    {
        if(s[i]=='?'){
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    if(l!=k&&l!=j&&j!=k)
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][l][j])%mod;
                }
            }
        }
        }
        else{
            for (int k = 0; k < 26; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    if(l!=k&&l!=(s[i]-'a')&&k!=(s[i]-'a'))
                    dp[i][k][s[i]-'a']=(dp[i][k][s[i]-'a']+dp[i-1][l][k])%mod;
                }
            }
        }
    }
    for (int j = 0; j < 26; j++)
    {
        for (int k = 0; k < 26; k++)
        {
            ans=(ans+dp[n-1][j][k])%mod;  
        }
    }
    cout<<ans;
    return 0;
}