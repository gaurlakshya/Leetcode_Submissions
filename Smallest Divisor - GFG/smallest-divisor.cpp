//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool ispossible(int val,vector<int>& nums,int threshold){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i]/val;
            if(nums[i]%val!=0)
                count++;
        }
        if(count<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Write your code here.
        sort(nums.begin(),nums.end());
        int l=1;
        int h=0;
        for(auto x:nums){
            h=max(h,x);
        }
        int ans=0;
        int mid=0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(ispossible(mid,nums,threshold)){
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends