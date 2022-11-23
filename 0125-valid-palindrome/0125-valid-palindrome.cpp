class Solution {
public:
    string convert(string s){
     string s2=s;
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        int n=s.size();
        
        string res="";
        for(int i=0;i<n;i++){
            if((s2[i]>='a' && s2[i]<='z')||(s2[i]>='0' &&s2[i]<='9')) res.push_back(s2[i]);
        }
        return res;
    }
    
    bool isPalindrome(string s) {
     //   int start=0,end=s.length()-1;
        string temp=convert(s);
        int start=0,end=temp.length()-1;
       // cout<<temp<<endl;
        while(start<=end){
            if(temp[start]!=temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};