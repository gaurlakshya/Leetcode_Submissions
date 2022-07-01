class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vec(n+1,vector<int>(n+1,0));
        vector<int> degree(n+1,0);
        for(auto edge:edges){
            vec[edge[0]][edge[1]]=1;
            vec[edge[1]][edge[0]]=1;
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int mn=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(vec[i][j]==1 && vec[j][k]==1 && vec[k][i]==1)
                        mn=min(mn,degree[i]+degree[j]+degree[k]-6);
                }
            }
        }
        if(mn==INT_MAX)
            return -1;
        return mn;
    }
};