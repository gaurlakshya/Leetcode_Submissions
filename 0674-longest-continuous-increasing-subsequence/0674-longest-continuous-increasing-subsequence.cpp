class Solution {
public:
    int findLengthOfLCIS(vector<int>& vec) {
             if (vec.size() == 1){
         //only one element is present
         //so print 1 length
        // cout<<1<<endl;
         return 1;
        }  
        //res is for the length
   
    int res = 1, noOfTimes = 1;
      for (int i = 0; i < vec.size() - 1; i++) {
         if (vec[i] < vec[i + 1]) {
            noOfTimes++;
            if(res<noOfTimes) res=noOfTimes;
            }
         else {
             //everytime we encounter a small element we change the sequence
            noOfTimes = 1;
         }
      }
      return res;
    }
};