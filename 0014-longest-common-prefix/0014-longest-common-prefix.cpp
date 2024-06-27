class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";  // Edge case: empty array
    
        string prefix = strs[0];  // Start with the first string as the initial prefix
        
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);  // Update prefix to the common part found
            if (prefix.empty()) break;  // If prefix becomes empty, no common prefix
        }
        
        return prefix.empty() ? "" : prefix;
    }
};