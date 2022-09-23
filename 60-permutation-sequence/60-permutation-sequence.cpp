class Solution {
public:
    string getPermutation(int n, int k) {
      int fact=1;
        vector<int> vec;
        for(int i=1;i<n;i++){
            fact*=i;
            vec.push_back(i);
        }
        string ans="";
        vec.push_back(n);
        k=k-1;
        while(true){
            if(vec.size()==0) break;
            else {
                int posn=k/fact;
                ans+=to_string(vec[posn]);
                vec.erase(vec.begin()+posn);
                k=k%fact;
                if(vec.size())
                fact=fact/vec.size();
            }
        }
        return ans;
    }
};