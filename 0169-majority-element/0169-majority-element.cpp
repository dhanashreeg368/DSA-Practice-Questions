class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        int n=nums.size()/2;
        for(auto num: mp) {
            if (num.second > n) {
                return num.first;
            }
        }
        return 0;
    }
};