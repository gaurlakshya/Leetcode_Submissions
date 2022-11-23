class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n=strs.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(strs[i]=="") return "";
            int sze=strs[i].size();
            mn=min(mn,sze);
        }
        if(n==1) return strs[0];
        bool flag=false;
        char val;
        for(int i=0;i<mn;i++){
            flag=false;
            val=strs[0][i];
            for(int j=0;j<strs.size(); j++){
                if(strs[j][i]!=val) return res;
            }
            res.push_back(val);
        }
        return res;
    }
};