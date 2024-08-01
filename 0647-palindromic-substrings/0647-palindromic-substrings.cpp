class Solution {
public:
    int countPalindromesAroundCenter(string &s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.length();i++) // visit every char
        {
            // calculate every odd len palindrome with i as the center
            res+=countPalindromesAroundCenter(s,i,i); 
            
            // calculate every even len palindrome with i and i+1 as the center
            res+=countPalindromesAroundCenter(s,i,i+1);    
        }
        return res; 
    }
};