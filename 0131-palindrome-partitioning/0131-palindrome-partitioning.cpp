class Solution {
public:
    bool isPalindrome(string s, int start,int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void func(int index,vector<string> &path,vector<vector<string>> &res,string &s){
        if(index==s.length()) {
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,path,res,s);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,path,res,s);
        return res;
    }
};