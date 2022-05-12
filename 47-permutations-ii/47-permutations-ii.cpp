class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sort the vector
        vector<vector<int>> res; //for storing res
        vector<int> permutation;
        vector<bool> possibilities(nums.size(),true); //taking possibilities vector
        backtrack(nums, permutation, possibilities, res); //backtrack function
        return res;       
    }
    
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<bool>& possibilities, vector<vector<int>>& res)
    {
        if(permutation.size()==nums.size()) //if we reach leaf node push it into res
        {
            res.push_back(permutation); 
        }
        else
        {
            for(int i=0;i<possibilities.size();i++)
            {
                if(i>0 && possibilities[i-1] && nums[i-1]==nums[i])
                {
                    continue;
                }
                if(possibilities[i])
                {
                    permutation.push_back(nums[i]);
                    possibilities[i]=false;
                    backtrack(nums, permutation, possibilities, res);
                    possibilities[i]=true;
                    permutation.pop_back();
                }
            }
        }
    }
};