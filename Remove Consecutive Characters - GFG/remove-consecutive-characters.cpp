//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string res;
        int n=S.length();
        res.push_back(S[0]);
        if(n==1) return res;
        if(n<=0) return "";
        int i=1;
        while(i<n){
            if(S[i]!=S[i-1])
            res.push_back(S[i++]);
            else i++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends