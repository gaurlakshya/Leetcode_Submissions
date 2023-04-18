//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
	    for(int i=0;i<n;i++){
	        for(int pv=0;pv<=i-1;pv++){
	            if(nums[pv]<nums[i])
	                dp1[i]=max(dp1[i],1+dp1[pv]);
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        for(int pv=n-1;pv>i;pv--){
	            if(nums[pv]<nums[i])
	                dp2[i]=max(dp2[i],1+dp2[pv]);
	        }
	    }
	    int maxi=-1;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends