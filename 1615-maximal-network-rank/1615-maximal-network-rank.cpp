class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n,0);
        vector<vector<int>> edge(n,vector<int>(n,0));
        for(int i=0;i<roads.size();i++){
            int x= roads[i][0];
            int y=roads[i][1];
            deg[x]++;
            deg[y]++;
            edge[x][y]++;
            edge[y][x]++;
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                ans=max(ans,deg[i]+deg[j]-edge[i][j]);
        }
        return ans;
    }
};