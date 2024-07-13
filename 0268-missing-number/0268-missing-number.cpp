class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        sort(nums.begin(), nums.end()); // sort the array to find the largest number
        int max_num=nums[n-1];
        //Summation of first N numbers:
        int exp_sum = (n * (n + 1)) / 2; 
        for(int i=0; i<n;i++) {
            sum+=nums[i]; // current sum
        }
        return abs(exp_sum-sum);
    }
};