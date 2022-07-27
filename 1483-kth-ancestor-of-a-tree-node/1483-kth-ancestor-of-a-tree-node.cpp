class TreeAncestor {
public:
    vector<vector<int>>look;
    TreeAncestor(int n, vector<int>& parent) {
        int si = floor(log2(n))+1;
        
        look.resize(n, vector<int>(si));
        for(int i=0;i<n;i++){
            look[i][0] = parent[i];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<si;j++){
                if(look[i][j-1]!=-1){
                    look[i][j] = look[look[i][j-1]][j-1];
                }else{
                    look[i][j]=-1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur = node;
        for(int b=0;b<32&&cur!=-1;b++){
            if(k&(1<<b)){
                cur = look[cur][b];
            }
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */