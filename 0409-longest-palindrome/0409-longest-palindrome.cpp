class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0); // Assuming ASCII characters
        
        for (char ch : s) {
            count[ch]++;
        }
        
        int length = 0;
        bool oddCountFound = false;
        
        for (int c : count) {
            if (c % 2 == 0) {
                length += c;
            } else {
                length += c - 1;
                oddCountFound = true;
            }
        }
        
        if (oddCountFound) {
            length++;
        }
        
        return length;

    }
};