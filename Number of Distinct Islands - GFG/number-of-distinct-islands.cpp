//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void bfs(int r, int c, vector<vector<int>> &vis,vector<vector<int>>& grid, vector<pair<int,int>> &vec,int r0, int c0){
      vis[r][c]=1;
      queue<pair<int,int>> q;
      q.push({r,c});
      vec.push_back({r-r0,c-c0});
      int delrow[]={-1,0,1,0};
      int delcol[]={0,1,0,-1};
      int n=grid.size();
        int m=grid[0].size();
      
      while(!q.empty()){
          int rf=q.front().first;
          int cf=q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
              int nr=rf+delrow[i];
              int nc=cf+delcol[i];
              if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                  vec.push_back({nr-r0, nc-c0});
                  vis[nr][nc]=1;
                  q.push({nr,nc});
              }
          }
         
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    bfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends