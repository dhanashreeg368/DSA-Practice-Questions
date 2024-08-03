class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0; // stores the max length
        int hash[256] = {0}; // hashmap to store the count of chars
        int n = s.length();
        
        // generate all sub-arrays using naive approach
        for(int i=0; i<n; i++) {
            int len = 0;
            int hash[256] = {0}; // reset hashmap to store the count of chars for each new starting index
            for(int j=i; j<n; j++) {
                if (hash[s[j]] == 1) { // if the count is already 1, that means an element is already present in hash, hence we do not need to inc j this time
                    break;
                } 
                len = j-i+1; // calculate current len
                maxLen = max(maxLen, len); // calculate max Len 
                hash[s[j]] = 1; // if encountered, mark it as 1 
            }
        }
        return maxLen;
    }
};