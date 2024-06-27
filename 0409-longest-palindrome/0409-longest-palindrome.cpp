class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int length=0;
        int oddCountFound=false;
        for (int i=0; i<s.length(); i++) {
            char ch=s[i];
            mp[ch]++;
        }
        for (auto x: mp) {
            if (x.second%2==0) {
                length+=x.second;
            }
            else {
                oddCountFound=true;
                length+=x.second-1;
            }
        }
        if (oddCountFound==true) {
            length+=1;
        }
        return length;
    }
};