//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod=1e9+7;
    long int solve(int n,vector<long>& dp){
        if(n==1) return 0;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        int val=((n-1)*(solve(n-1,dp)%mod+solve(n-2,dp)%mod))%mod;
        return dp[n]= val;
    }

    long int disarrange(int N){
        // code here
        vector<long> dp(N+1,-1);
        int res=solve(N,dp);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends