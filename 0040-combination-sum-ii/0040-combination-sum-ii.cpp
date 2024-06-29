class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> combinations;
        int sum=0;
        sort(candidates.begin(), candidates.end());
        combinationSums(0, combination, combinations, candidates, target);
        return combinations;
    }
    
    void combinationSums(int idx, vector<int>& combination, vector<vector<int>>& combinations, vector<int>& candidates, int target) {    
        
        // Calculate the current sum
        int sum = accumulate(combination.begin(), combination.end(), 0);
        
        // Base case: if the sum equals the target, add the combination to the results
        if (sum == target) {
            combinations.push_back(combination);
            return;
        }
        
        // Base case: if the sum exceeds the target or idx is out of bounds, return
        if (sum > target || idx >= candidates.size()) {
            return;
        }
        
        combination.push_back(candidates[idx]);
        combinationSums(idx+1, combination, combinations, candidates, target);
        combination.pop_back();
        
        // Exclude the current candidate and move to the next unique candidate
        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++;
        }
        
        // not pick element
        combinationSums(idx+1, combination, combinations, candidates, target);
    }
};