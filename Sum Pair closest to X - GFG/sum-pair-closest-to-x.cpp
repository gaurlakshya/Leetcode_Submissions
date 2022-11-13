//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int n=arr.size();
        int temp_a=arr[0];
        int temp_b=arr[n-1];
        int i=0,j=n-1;
        int mn=INT_MAX;
        while(i<j){
            if(arr[i]+arr[j]<x){
                //mn=min(mn,abs(arr[i]+arr[j]-x))
               if(mn>abs(arr[i]+arr[j]-x)){
                   mn=abs(arr[i]+arr[j]-x);
                temp_a=arr[i];
                temp_b=arr[j];
               }
                i++;
            }else{
              //   mn=min(mn,abs(arr[i]+arr[j]-x))
                 if(mn>abs(arr[i]+arr[j]-x)){
                     mn=abs(arr[i]+arr[j]-x);
                  temp_a=arr[i];
                temp_b=arr[j];
                
                 }
                 j--;
            }
        }
        vector<int> res;
        res.push_back(temp_a);
        res.push_back(temp_b);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends