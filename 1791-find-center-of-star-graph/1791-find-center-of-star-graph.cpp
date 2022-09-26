class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        int val1=edges[0][0];
        int val2=edges[0][1];
        for(int i=0;i<n;i++){
            if(edges[i][0]!=val1 && edges[i][1]!=val1)
                return val2;
            else if(edges[i][0]!=val2 && edges[i][1]!=val2)
                return val1;
        }
        return 0;
    }
};