class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            if(i==0){
                res.push_back({1});
                continue;
            }
            if(i==1){
                res.push_back({1,1});
                continue;
            }
            else{
                vector<int> vec(i+1);
                vec[0]=1,vec[i]=1;
                for(int j=1;j<i;j++){
                    vec[j]=res[i-1][j]+res[i-1][j-1];
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};