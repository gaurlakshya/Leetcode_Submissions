class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int diff=0;diff<s.size();diff++){
            for(int i=0,j=diff;j<n;j++,i++){
                if(diff==0)
                    dp[i][j]=true;
               else if(diff==1)
                    if(s[i]==s[j])
                        dp[i][j]=true;
                else
                    dp[i][j]=false;
                else{
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j])
                    res++;
            }
        }
        return res;
    }
};