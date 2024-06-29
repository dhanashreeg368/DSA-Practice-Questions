class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int>subset;
        createSubsets(0, nums, subsets, subset);
        return subsets;
    }
    
    void createSubsets(int idx, vector<int> nums, vector<vector<int>>& subsets, vector<int>& subset) {
        if (idx>=nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        createSubsets(idx+1, nums, subsets, subset);
        subset.pop_back();
        createSubsets(idx+1, nums, subsets, subset);
    }
};