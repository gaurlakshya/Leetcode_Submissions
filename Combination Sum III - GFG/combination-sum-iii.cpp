//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int ind,vector<int>& res, vector<vector<int>>& ans,vector<int> nums,int sze,int sum){
        if(ind>=nums.size()){
            if(res.size()==sze && sum==0){
                ans.push_back(res);
            }
            return;
        }
        if(nums[ind]<=sum){
            sum-=nums[ind];
            res.push_back(nums[ind]);
            solve(ind+1,res,ans,nums,sze,sum);
            res.pop_back();
            sum+=nums[ind];
        }
        solve(ind+1,res,ans,nums,sze,sum);
       
        
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
         vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,res,ans,nums,k,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends