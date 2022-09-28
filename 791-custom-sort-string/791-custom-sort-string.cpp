class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ump;
        for(char x:s)
            ump[x]++;
       string ans;
        for(int i=0;i<order.size();i++){
            if(ump.find(order[i])!=ump.end())
                while(ump[order[i]]--)
                    ans+=order[i];
        }
        for(auto itr:ump)
            if(ump[itr.first]>0)
                while(ump[itr.first]--)
                ans+=itr.first;
        return ans;
    }
};