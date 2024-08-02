class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length()!=goal.length()) {
            return false;
        }
        s+=s;
        int idx = s.find(goal);
        if (idx>=0 && idx<=s.size()) {
            return true;
        } else {
            return false;
        }
    }
};