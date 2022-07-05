class Solution {
public:
    void mark_island(vector<vector<char>> &arr,int i,int j,int n,int m){
        if(i<0 || i>=n|| j<0 || j>=m || arr[i][j]!='1' ) return;
        arr[i][j]='2';
        mark_island(arr,i+1,j,n,m);
        mark_island(arr,i,j+1,n,m);
        mark_island(arr,i-1,j,n,m);
        mark_island(arr,i,j-1,n,m);
    } 
    int numIslands(vector<vector<char>>& grid) {
          ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                mark_island(grid,i,j,n,m);
                    res+=1;
                }
            }
        }
        return res;
    }
};
/*
Input: grid = [
  ["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
Output: 3
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/