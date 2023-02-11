//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &dp,vector<int>& height,int index){
        if(index==0)return 0;
        if(dp[index]!=-1) return dp[index];
        int left=solve(dp,height,index-1)+abs(height[index]-height[index-1]);
       int right=INT_MAX;
       if(index>1)
         right=solve(dp,height,index-2)+abs(height[index]-height[index-2]);
         
        return dp[index]=min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        solve(dp,height,n-1);
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends