class Solution {
public:
   static bool comp(string f,string s){
        int i=0;
        string temp1=f+s;
        string temp2=s+f;
        while(temp1[i] && temp2[i]){
            if(temp1[i]>temp2[i]) return true;
            else if (temp1[i]<temp2[i] ) return false;
            i++;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) flag=true;
        }
        if(flag==false) return "0";
        vector<string> res;
        for(int i=0;i<n;i++){
            res.emplace_back(to_string(nums[i]));
        }
        sort(res.begin(),res.end(),comp);
        string str="";
        for(int i=0;i<n;i++){
            str+=res[i];
        }
        return str;
    }
};