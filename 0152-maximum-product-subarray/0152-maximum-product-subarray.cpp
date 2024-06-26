#include <algorithm> // For std::max
#include <climits>   // For INT_MIN
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double maxi = INT_MIN;
        double prefix = 1,suffix = 1;
        for(int i = 0; i < nums.size(); i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            maxi = max(maxi,max(prefix,suffix));
        }
        return (int)maxi;
    }
};