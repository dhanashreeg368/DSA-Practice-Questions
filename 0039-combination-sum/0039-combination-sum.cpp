class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        int sum=0;
        combineSum(0, sum, candidates, target, combinations, combination);
        return combinations;
    }
    
    void combineSum(int idx, int sum, vector<int>& candidates, int target, vector<vector<int>>& combinations, vector<int>& combination) {
        
        sum = accumulate(combination.begin(), combination.end(), 0);     
        
        // Base case: if sum equals target, add combination to results
        if (sum == target) {
            combinations.push_back(combination);
            return;
        }
        
        // Base case: if sum exceeds target or idx is out of bounds, return
        if (sum > target || idx >= candidates.size()) {
            return;
        }
        
        // add to combination
        combination.push_back(candidates[idx]);
        combineSum(idx, sum, candidates, target, combinations, combination);
        
        combination.pop_back();
        combineSum(idx+1, sum, candidates, target, combinations, combination);
    }
};