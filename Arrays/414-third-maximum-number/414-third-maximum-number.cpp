class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> res{s.begin(),s.end()};
        return res.size()<3 ? *res.rbegin() : *(res.rbegin() + 2);
    }
};