class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp; // map to store the num and freq of target
        for(int num: target) { // keep a target map for freq
            mp[num]++;
        }
        
        for(int num: arr) { 
            if(mp.find(num) == mp.end() || mp[num] == 0) { // check if arr[i] is not in the map 
                return false; // if not in the map return false;
            } else {
                mp[num]--; // if already present in the map, decr the count of it 
            }
        }
        return true;
    }
};