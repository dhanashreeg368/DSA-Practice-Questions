class Solution {
public:

    void f(int ind, string curr, string &digits, map<int, string> &m, vector<string> &ans){

        if(ind == digits.size()){ // base case 
            ans.push_back(curr);
            return;
        }

        int num = digits[ind] - '0';
        string letters = m[num];

        for(auto &letter : letters){

            curr.push_back(letter);
            f(ind + 1, curr, digits, m, ans);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        
        map<int, string> m = { // map 
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        vector<string> ans; // ans
        if(digits.empty()) return ans;

        f(0, "", digits, m, ans);
        return ans;  
    }
};