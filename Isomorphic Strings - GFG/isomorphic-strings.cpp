//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int s1=str1.length();
        int s2=str2.length();
        if(s1!=s2) return false;
        vector<int> str1_map(128,0);
        vector<int> str2_map(128,0);
        
        for(int i=0;i<s1;i++){
            if(str1_map[str1[i]]==0 && str2_map[str2[i]]==0) {
                str1_map[str1[i]]=i+1;
                str2_map[str2[i]]=i+1;
            }
            else if(str1_map[str1[i]] !=str2_map[str2[i]]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends