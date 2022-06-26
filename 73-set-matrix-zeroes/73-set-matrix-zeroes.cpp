class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row(n,1);
        vector<int> col(m,1);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    col[i]=0;
                    row[j]=0;
                }
            }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(col[i]==0 || row[j]==0)
                    matrix[i][j]=0;
            }
        }
    }
};