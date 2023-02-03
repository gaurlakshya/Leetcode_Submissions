//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
    bool static comp(vector<int>& v1,vector<int>& v2){
        return v1[0]<v2[0];
    }
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        int ans=0;
        sort(intervals.begin(),intervals.end(),comp);
        if(n==0 || n==1) return ans;
        vector<int> prev=intervals[0];
        for(int i=1;i<n;i++){
            if(prev[1]>intervals[i][0]){
                ans++;
                if(prev[1]>=intervals[i][1]) prev=intervals[i];
            }else
            prev=intervals[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends