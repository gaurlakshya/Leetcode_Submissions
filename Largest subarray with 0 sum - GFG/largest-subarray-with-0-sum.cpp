//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mpp;
        int sum=0;
        int anslen=0;
        int mxlen=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) mxlen=i+1;
            if(mpp.count(sum)){
                anslen=i-mpp[sum];
                mxlen=max(mxlen,anslen);
            }else
            mpp[sum]=i;
        }
        return mxlen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends