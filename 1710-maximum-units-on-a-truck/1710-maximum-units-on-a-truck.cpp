class Solution {
public:
        static bool comp(vector<int> &a, vector<int> &b) { return b[1] < a[1]; };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
           sort(boxTypes.begin(), boxTypes.end(), comp); // sorting based on decreasing units
        
        int units = 0;
		// if capacity == 0, return totals units stored
        for (int i = 0 ; i < boxTypes.size() and truckSize > 0; i++) {
            int a = min(truckSize, boxTypes[i][0]); // number of boxes that can be stored   
            units += a*boxTypes[i][1]; // updating units collected
            truckSize -= a; // updating capacity
        }
        return units;
    }
};