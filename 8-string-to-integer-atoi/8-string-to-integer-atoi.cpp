class Solution {
public:

int myAtoi(string s) {
    
    int k = 0;
    while(s[k] == ' ')k++;        // To skip initial blanks
    
    bool neg = 0;
    if(s[k] == '-'){              // if there is a -ve sign
        neg = 1;                  // mark the number as negative
        k++;
    }
    else if(s[k] == '+')k++;      // if  +ve sign, just skip it
    
    long long sum = 0;
    
    for(int i = k; i < s.length(); i++){    
        
        if(s[i] <= '9' && s[i] >= '0'){
            sum *= 10;
            sum += (s[i]-'0');
        }
        else break;
        
        if(sum > INT_MAX){
            return neg? INT_MIN : INT_MAX;
        }
    }
    
    return neg? (-1*sum) : sum;
}
};