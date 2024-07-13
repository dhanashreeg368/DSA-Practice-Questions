class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) { // if size is zero return 0
            return 0;
        }
        int k=1; // k=1 as first element will always be unique
        for(int i=1; i<nums.size(); i++) { // iterate through the array
            if (nums[i]!=nums[i-1]) { // if curr and prev are not equal, incr k
                nums[k]=nums[i]; // place the unique element in nums
                k++;
            }
        }
        return k;
    }
};