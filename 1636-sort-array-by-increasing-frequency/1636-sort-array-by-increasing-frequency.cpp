class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // count the frequency of each number
        map<int, int> freqMap;
        for(auto num: nums) { // freqMap = {1: 2, 2: 3, 3: 1}
            freqMap[num]++;
        }
        
        map<int, vector<int>> mp2;
        for(auto it: freqMap) { // mp2 = {2: [1], 3: [2], 1: [3]}
            mp2[it.second].push_back(it.first);
        }
        
        vector<int> result;
        for(auto it : mp2) {
            if(it.second.size() > 1) {
                std::sort(it.second.rbegin(), it.second.rend());
            }
            for(int i = 0; i < it.second.size(); i++) {
                int freq = it.first;
                while(freq != 0) {
                    result.push_back(it.second[i]);
                    freq--;
                }
            }
        } 
        return result;
    }
};