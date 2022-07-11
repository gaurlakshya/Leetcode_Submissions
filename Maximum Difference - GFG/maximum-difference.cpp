// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int a[], int n)
     {
     //Your code here
     int left[n];
     left[0]=0;
     int k;
     bool flag;
     
     for(int i=1;i<n;i++)
     {
         k=i-1;
         flag=false;
         
         while(k>=0)
         {
             if(a[i]>a[k])
             {
                left[i]=a[k];
                flag=true;
                break; 
             }
             k--;
         }
         
         if(flag==false)
         left[i]=0;
     }

     int right[n];
     right[n-1]=0;
     
     for(int i=n-2;i>=0;i--)
     {
       k=i+1;
       flag=false;
         
         while(k<=(n-1))
         {
             if(a[i]>a[k])
             {
                right[i]=a[k];
                flag=true;
                break; 
             }
             k++;
         }
         if(flag==false)
         right[i]=0;
     }
 
     int res=0;
     for(int i=0;i<n;i++)
     {
         res=max(res,abs(left[i]-right[i]));
     }
     
     return res;
   }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends