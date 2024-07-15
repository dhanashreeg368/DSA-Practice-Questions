class Solution {
public:
    void recurPermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& freq) {
        if (ds.size() == nums.size()) { // if base case is reached put it in ans
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++) { // we will have n options to fill a place 
            if(!freq[i]) { // if not visited then only consider
                ds.push_back(nums[i]); // push and mark as visited
                freq[i]=1;
                recurPermute(nums, ds, ans, freq);
                freq[i]=0; // remove and mark as unvisited
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // store ans
        vector<int> ds; // temporary array for storing the values and removing
        vector<int> freq(nums.size(), 0); // set freq for all as 0 using vector
        recurPermute(nums, ds, ans, freq);
        return ans;
    }
};