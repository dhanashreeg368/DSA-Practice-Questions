class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int start=0,end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (nums[mid]==target)
            {
                res=mid;
                end=mid-1;
            }
            else if (target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int start=0,end=nums.size()-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (nums[mid]==target)
            {
                res=mid;
                start=mid+1;
            }
            else if (target>nums[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0]=findFirst(nums,target);
        result[1]=findLast(nums,target);
        return result;
    }
};