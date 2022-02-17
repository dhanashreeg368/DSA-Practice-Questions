class Solution {
public:
    vector<vector<int>> res;
    int n;  
    void solve(vector<int>& nums, int i, int target, vector<int> subset){
        //base case
        if(target < 0) return;
        if(!target) {
            //combination formed
            res.push_back(subset);
            return;
        }
        if(i==n) return; //couldn't form a combination
        
        //recursive case
        //now we can take any element any number of times
        solve(nums, i+1, target, subset); //we didn't include this element
        while(target > 0){
            subset.push_back(nums[i]);
            target -= nums[i];
            solve(nums, i+1, target, subset);
        }
        return; //doesn't matter in void functions but it's always safe to use return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> subset;
        solve(candidates, 0, target, subset);
        return res;
    }
};