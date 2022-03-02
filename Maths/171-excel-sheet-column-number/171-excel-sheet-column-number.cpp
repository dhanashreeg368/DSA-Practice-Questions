class Solution {
public:
    int titleToNumber(string columnTitle) {
    // This process is similar to binary-to-decimal conversion 
    int res = 0;
    for (const auto& c : columnTitle)
    {
        res *= 26;
        res += c  - 'A' + 1;
    }
    return res;
    }
};