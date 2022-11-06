class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        if(n==0) return 0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else st.push(s[i]);
            }
        }
        int a=0,b=0;
        while(!st.empty()){
            if(st.top()=='(') a++;
            else b++;
            st.pop();
        }
        return a+b;
    }
};