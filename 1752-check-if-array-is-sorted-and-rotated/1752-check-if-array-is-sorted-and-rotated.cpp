class Solution {
public:
    bool check(vector<int>& nums) { 
        // [3,4,5,1,2] here 1 is the breaking point as only 5>1
        int count = 0; // count to check the breaking point
        for (int i=0; i<nums.size(); i++) { // iterate through the array
            if (nums[i]>nums[(i+1)%nums.size()]) { // if breaking incr cnt by 1
                count++; 
            }
        }
        if (count<=1) { // if only 1 breaking point return true 
            return true;
        }
        return false;
    }
};