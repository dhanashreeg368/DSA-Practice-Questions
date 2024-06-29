class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> set1;
        sort(nums.begin(),nums.end());
        subsets2(0, nums, set1, ans);
        return ans;
    }
    
    void subsets2(int idx, vector<int>& nums, vector<int>& set1, vector<vector<int>>& ans) {
        ans.push_back(set1);

        for (int i = idx; i<nums.size(); i++) {
            if (i!=idx && nums[i]==nums[i-1]) {
                continue;
            }
            set1.push_back(nums[i]);
            subsets2(i+1, nums, set1, ans);
            set1.pop_back();
        }
    }
};