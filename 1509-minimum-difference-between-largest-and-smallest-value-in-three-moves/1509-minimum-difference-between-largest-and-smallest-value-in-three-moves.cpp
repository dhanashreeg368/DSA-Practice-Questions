class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        
        // Possible scenarios after making at most three moves
        int minDiff = INT_MAX;
        // Change the three largest elements
        minDiff = min(minDiff, nums[n-4] - nums[0]);
        // Change the two largest elements and the smallest element
        minDiff = min(minDiff, nums[n-3] - nums[1]);
        // Change the largest element and the two smallest elements
        minDiff = min(minDiff, nums[n-2] - nums[2]);
        // Change the three smallest elements
        minDiff = min(minDiff, nums[n-1] - nums[3]);
        
        return minDiff;
    }
};