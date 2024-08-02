class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(); // size of the array
        int totalOnes = count(nums.begin(), nums.end(), 1); // count the total number of ones 
        
        if (totalOnes == 0 || totalOnes == n) {
            return 0;
        }
        
        int onesInWindow = 0; // caclulate 1s in first window
        for(int i = 0; i<totalOnes; i++) { 
            onesInWindow += nums[i];
        }
        int maxNoOfOnes = onesInWindow; // they will be max
        
        // consider array as n + totalOnes 
        for (int i = totalOnes; i< n + totalOnes; i++) { 
            // when we go to next element, add next ele and subtract the first element from window
            onesInWindow += nums[i%n] - nums[(i - totalOnes) % n]; 
            maxNoOfOnes = max(maxNoOfOnes, onesInWindow);
        }
        return totalOnes - maxNoOfOnes;
    }
};