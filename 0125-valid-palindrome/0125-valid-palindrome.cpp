class Solution {
public:
    // solving using recursion
    bool isPalindrome(string s) {
        
        // Preprocess the string to remove non-alphanumeric characters and convert to lowercase
        string filteredString;
        for (char c : s) {
            if (isalnum(c)) {
                filteredString += tolower(c);
            }
        }
        // Use the recursive palindrome check function
        return palindrome(filteredString, 0, filteredString.length() - 1);
    }
    
    bool palindrome(string& s, int start, int end) {
        if (start>=end) {
            return true;
        }
        if (s[start]!=s[end]) {
            return false;
        } 
        return palindrome(s, start+1, end-1);
    }
};