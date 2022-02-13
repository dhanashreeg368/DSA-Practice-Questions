class Solution {
public:
    void subsets(vector<int>nums,int idx,vector<vector<int>>& result)
    {
        if(idx==nums.size()-1) //if size is one-only one element
        {
            result.push_back({}); //push empty set 
            result.push_back({nums[idx]}); //push set itself
        }
        else
        {
            subsets(nums,idx+1,result); //call function
            int n=result.size();
            for(int i=0;i<n;i++)
            {
                vector<int>r=result[i];
                r.push_back(nums[idx]); //r is current subset
                result.push_back(r);  //push r into result
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {{}};
        vector<vector<int>>  result;
        subsets(nums,0,result); //recursive function
        return result;
    }
};