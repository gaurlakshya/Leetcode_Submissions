class Solution {
public:
    int compress(vector<char>& arr) {
        
        int n = arr.size();
        
        // we will insert the compressed character at j
        
        int j = 0;
        
        int i = 0;
        
        while(i < n)
        {
            // count the no. of consecutive characters
            
            int count = 1;
            
            while(i + 1 < n && arr[i] == arr[i + 1])
            {
                count++;
                
                i++;
            }
            
            // insert at j according to count
            
            if(count == 1)
            {
                arr[j++] = arr[i];
            }
            else
            {
                arr[j++] = arr[i];
                
                // split the count then insert at j
                
                string str = to_string(count);
                
                for(int k = 0; k < str.size(); k++)
                {
                    arr[j++] = str[k];
                }
            }
            
            i++;
        }
        
        return j;
    }
};