//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // int solve(int i,int j ,int n, vector<vector<int>>& triangle){
    //     if(i==n-1) return triangle[i][j];
    //     int down=solve(i+1,j,n,triangle)+triangle[i][j];
    //     int diag=solve(i+1,j+1,n,triangle)+triangle[i][j];
    //     return min(down,diag);
    // }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        // int i=0,j=0;
        // int res=solve(i,j,n,triangle);
        // return res;
        
        vector<int> front(n,0),curr(n,0);
        for(int i=0;i<n;i++){
            front[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int diag=triangle[i][j]+front[j+1];
                curr[j]=min(down,diag);
            }
            front=curr;
        }
        return front[0];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends