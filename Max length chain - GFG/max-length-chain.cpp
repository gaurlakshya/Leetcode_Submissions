// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

int solve(vector<pair<int,int>>&v,int id,int n,int prev){
   if(id==n)
   return 0;
 int ans=0;
   if((prev==-1)||v[id].first>v[prev].second)
   {
  ans=max(ans,solve(v,id+1,n,id)+1);
   }
   ans=max(ans,solve(v,id+1,n,prev));
   return ans;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
vector<pair<int,int>>v;
for(int i=0;i<n;i++)
{
   v.push_back({p[i].first,p[i].second});
 }
sort(v.begin(),v.end());
return solve(v,0,n,-1);

}