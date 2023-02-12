//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int solve(vector<int>& height,int index,int k){
    //     if(index==0) return 0;
    //     int mn=INT_MAX;
    //     for(int i=1;i<=k;i++){
    //         int val=INT_MAX;
    //         if(index-i>=0)
    //          val=solve(height,index-i,k)+abs(height[index]-height[index-i]);
    //         mn=min(mn,val);
    //     }
    //     return mn;
    // }
    // int minimizeCost(vector<int>& height, int n, int k) {
    //     // Code here
        
    //     int ans=solve(height,n-1,k);
    //     return ans;
    // }
    int solve(vector<int>& height,int index,int k,vector<int>& dp){
        if(index==0) return dp[0]=0;
        int mn=INT_MAX;
        if(dp[index]!=-1) return dp[index];
        for(int i=1;i<=k;i++){
            int val=INT_MAX;
            if(index-i>=0)
             val=solve(height,index-i,k,dp)+abs(height[index]-height[index-i]);
            mn=min(mn,val);
        }
        return dp[index]=mn;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n+1,-1);
        int ans=solve(height,n-1,k,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends