class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (int i=0; i<s.length(); i++) { // 
            char ch=s[i];
            mp[ch]++;
        }
        for (int i=0; i<t.length(); i++) {
            char ch=t[i];
            mp[ch]--;
        }
        for (auto x: mp) {
            if (x.second!=0) {
                return false;
            }
        }
        return true;
    }
};