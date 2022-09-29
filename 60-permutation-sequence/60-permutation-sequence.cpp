class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ans;
        int fact=1;
        //ans.push_back(fact);
        for(int i=1;i<n;i++){
            fact*=i;
            ans.push_back(i);
        }
        ans.push_back(n);
        k=k-1;
        string res="";
        while(ans.size()){
            
            res+=to_string(ans[k/fact]);
            
            ans.erase(ans.begin()+(k/fact));
            if(!ans.size()) break;
            k=k%fact;
            fact=fact/ans.size();
        }
        return res;
    }
};