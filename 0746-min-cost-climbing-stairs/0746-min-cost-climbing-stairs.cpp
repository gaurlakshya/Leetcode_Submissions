class Solution {
public:
  int solve(vector<int>&cost,int n,vector<int>&dp){
      if(n==0) return  dp[0]=cost[0];
      if(n==1) return dp[1]=cost[1];
      if(dp[n]!=-1) return dp[n];
      int mn=solve(cost,n-1,dp);
      if(n>1)
          mn=min(mn,solve(cost,n-2,dp));
      return dp[n]=mn+cost[n];
  }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
       int n=cost.size();
    vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};