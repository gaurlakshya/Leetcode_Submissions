class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
       long long int res=0,sum1=0,sum2=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) {sum1+=nums1[i++];            sum1%=1000000007;}
            else if(nums1[i]>nums2[j]) {sum2+=nums2[j++];

            sum2%=1000000007;}
            else{
                res+=max(sum1,sum2)+nums1[i];
                res%=1000000007;
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }
        while(i<n) sum1+=nums1[i++];
        while(j<m) sum2+=nums2[j++];
        res+=max(sum1,sum2);
        res%=1000000007;
        return res;
    }
};


 