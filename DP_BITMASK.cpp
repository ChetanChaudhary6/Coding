#include<bits/stdc++.h>
using namespace std;
#define int long long int

/*dp on bitmasking
when n is generally 12 to 20
here brute frce is to calculate all permutations 
we use dp to minimise time complexity
n! ---->  2^n
we make a mask which stores subproblem
if the current bit is '1' means it is available for taking
else it has already taken
final answer will be dp[11111...]
we use index to keep track of previous result as there is relation between consecutive elements
*/


//here is a problem for calculating superstring of smallest size
//means a string which contain all substrings in it

class Solution {
public:
    string findSuperstring(string& str1,string& str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int overlapLength = 0;
        for (int i = min(len1, len2); i >= 0; i--) {
            if (str1.substr(len1 - i) == str2.substr(0, i)) {
                overlapLength = i;
                break;
            }
        }
        string superstring = str2.substr(overlapLength);
        return superstring;
    }
    string fun(int n,int mask,vector<vector<string>>&dp,vector<string>&words,vector<vector<string>>&superstr){
        if(mask==0)return dp[n][mask]="";
        if(dp[n][mask]!="")return dp[n][mask];
        string s="";
        int k=1;
        for(int i=0;i+1<words.size();i++){
            if(mask&k){
                string s1=superstr[n][i];
                s=s1+fun(i,mask^k,dp,words,superstr);
            }
            if(dp[n][mask]=="")dp[n][mask]=s;
            if(dp[n][mask].size()>s.size())dp[n][mask]=s;
            k*=2;
        }
        return dp[n][mask];
    }
    string shortestSuperstring(vector<string>& words) {
        int n=words.size(),mask=(1<<n)-1;
        words.push_back("");
        vector<vector<string>>superstr(n+1,vector<string>(n+1,""));
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)if(i!=j)superstr[i][j]=findSuperstring(words[i],words[j]);
        vector<vector<string>>dp(n+1,vector<string>(mask+1,""));
        return fun(n,mask,dp,words,superstr);
    }
};

signed main()
{   
    Solution obj;
    vector<string>words={"catg","ctaagt","gcta","ttca","atgcatc"};
    cout<<obj.shortestSuperstring(words);
    return 0;
}