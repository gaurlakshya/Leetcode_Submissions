class Solution {
public:
    int addDigits(int num) {
        if(num>=0 && num<=9)
            return num;
        int count=0;
        while(num>9){
                    long sum=0;

            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            num=sum;
            
        }
        return num;
    }
};