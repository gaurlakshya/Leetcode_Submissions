//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPossible(int arr[],int n,int m,int d){
        int sum=0;
        int total_days=1;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=m ) sum+=arr[i];
            else{
                sum=arr[i];
                total_days++;
                
        }
        }
        if(total_days<=d) return true;
        return false;
    }
    int leastWeightCapacity(int weights[], int n, int days) {
        // code here
        int sum=0;
        int mx=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(weights[i]>mx) mx=weights[i];
            
        }
        int lo=mx;
        int hi=sum;
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isPossible(weights,n,mid,days)){
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends