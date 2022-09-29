class Solution {
public:
    bool isPalindrome(string s,int st,int en){
        while(st<en){
            if(s[st++]!=s[en--])
                return false;
        }
        return true;
    }
    void solve(int index,vector<vector<string>>&res,vector<string> &temp,string s){
        if(index==s.length()){
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,res,temp,s);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(0,res,temp,s);
        return res;
    }
};