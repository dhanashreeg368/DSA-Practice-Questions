class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp; // unordered map to store the count of the strings
        for(string it: arr) {
            mp[it]++; // store in map all the counts 
        }
        int kDistinct = 0;      
        for(string it: arr) { // iterate in original array, as we need to store the order as it is
            if (mp[it] == 1) { // if count is one, add in kDistinctCount
                kDistinct+=1;
                if (kDistinct == k) { 
                    return it;
                }
            }
        }
        return "";
    }
};