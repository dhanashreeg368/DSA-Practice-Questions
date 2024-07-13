class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int num=0;
        for(int i=0; i<n; i++) {
            num^=nums[i];
        }
        return num;
    }
};