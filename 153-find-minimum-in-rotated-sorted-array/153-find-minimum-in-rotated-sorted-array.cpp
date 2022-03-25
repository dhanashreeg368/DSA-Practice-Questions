class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int prev = nums.at((mid + n - 1) % n);
        int next = nums.at((mid + 1) % n);
      
        if (prev >= nums.at(mid) && next >= nums.at(mid))
        {
           
            return nums.at(mid);
        }

        if (nums.at(low) < nums.at(high))
        {
            high = mid - 1; // go to left
        }
        else if (nums.at(low) <= nums.at(mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
    }
};