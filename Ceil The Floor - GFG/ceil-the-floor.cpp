//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int ans1=-1;
    int ans2=-1;
    sort(arr,arr+n);
    //floor value 
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
            int mid=lo+(hi-lo)/2;

        if(arr[mid]==x) {
            ans1=arr[mid];
            break;
        }
        else if(arr[mid]>x) hi=mid-1;
        else {
            ans1=arr[mid];
            lo=mid+1;
        }
        
    }
    
    
    lo=0;
    hi=n-1;
   
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
        if(arr[mid]==x) {
            ans2=arr[mid];
            break;
        }
        else if(arr[mid]>x){ans2=arr[mid]; hi=mid-1;}
        else {
            
            lo=mid+1;
        }
        
    }
    return {ans1,ans2};
}