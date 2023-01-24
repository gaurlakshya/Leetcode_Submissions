//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(string &val,vector<string> &ans,int open,int close){
        if(open<0 || close<0) return;
        if(open==0 && close==0){
            ans.push_back(val);
            return;
        }
        if(open<close){
            val.push_back(')');
            solve(val,ans,open,close-1);
            val.pop_back();
        }
        val.push_back('(');
        solve(val,ans,open-1,close);
        val.pop_back();
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string val="";
        int open=n;
        int close=n;
        solve(val,ans,open,close);
        return ans;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends