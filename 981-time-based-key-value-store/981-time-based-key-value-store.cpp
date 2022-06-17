class TimeMap {
    unordered_map<string,vector<pair<string,int>>> ts;
public:
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       ts[key].push_back({value,timestamp}); 
    }
    
    string get(string key, int timestamp) {
        int lo=0;
        int high=ts[key].size()-1;
        string res="";
        while(lo<=high){
            int mid=lo+(high-lo)/2;
           if(ts[key][mid].second == timestamp) return ts[key][mid].first;
            else if(ts[key][mid].second < timestamp) {
                res = ts[key][mid].first;
                lo = mid + 1;  
            } 
            else high = mid-1;
        }
        return res;
        }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */