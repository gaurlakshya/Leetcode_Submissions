class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return mid;
            else if(arr[mid]<arr[mid+1])
                l=mid+1;
            else 
                r=mid;
        }
        return l;
    }
};