class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0; // stores the max length
        int hash[256] = {0}; // hashmap to store the count of chars
        int n = s.length();
        int left=0, right = 0; 
        
        while(right < n) { // iterating till last using right ptr
            
            // if the char has already a count, that means, already present in that case, 
            // we need to shrink left window till the count is greater than 0
            if (hash[s[right]] > 0) {
                hash[s[left]]--;
                left+=1;
            }
            
            // if visited for first time, then update maxLen, mark as visited and update the right ptr
            if (hash[s[right]]!=1) {
                maxLen = max(maxLen, right-left+1);
                hash[s[right]] = 1; 
                right+=1;
            }
        }
        return maxLen;
    }
};