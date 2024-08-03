class Solution {
public:
    int longestOnes(vector<int>& nums, int k) { // longest subarray with atmost k zeroes 
        int n = nums.size();
        int maxLen = 0;
        int l=0, r=0;
        int zeroes = 0; // count zeroes 
        while(r<n) {
            if (nums[r] == 0) { // if zero encountered, incr count
                zeroes++;
            }
            if (zeroes > k) { // if not valid condtion, left++, and if 0 encountered, decr it from cnt
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            if (zeroes <=k) { // if valid condition --> caluclate max length
                maxLen = max(maxLen, r-l+1);
            }
            r+=1;
        }
        return maxLen;
    }
};