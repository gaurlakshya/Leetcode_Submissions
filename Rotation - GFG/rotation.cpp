//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    //min element
        int l=0;
        int h=n-1;
        int mid;
        int idx=0;
        while(l<=h){
            mid=l+(h-l)/2;
            if(nums[mid]<nums[idx]){
                h=mid-1;
                idx=mid;
        }
            else{
                l=mid+1;
            }
    }
                    return idx;

	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends