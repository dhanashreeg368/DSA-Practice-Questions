class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k>n) { // edge case
            k=k%n;  
        }
        reverse(nums.begin(), nums.end()); // reverse an entire array
        reverse(nums.begin(), nums.begin() + k); // reverse first k elements
        reverse(nums.begin() + k, nums.end()); // reverse remianing n-k elements
    }
};