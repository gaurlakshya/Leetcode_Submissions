class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            vec.push_back(i);
        }
        vec.push_back(n);
        k=k-1;
        string ans="";
        while(true){
           ans+=to_string(vec[k/fact]);
          
            vec.erase(vec.begin()+(k/fact));
                  if(vec.size()==0) break;
            k=k%fact;
            fact=fact/vec.size();
            
        }
        return ans;
    }
};