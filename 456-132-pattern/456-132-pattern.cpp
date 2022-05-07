class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        if(n <= 2) return false;
       
        int mn = nums[0];
        
        map<int, int> m;
        for(int i=1; i<n; i++) m[nums[i]]++;
        
        for(int i=1; i<n-1; i++)
        {
			//read this after reading the below two cases
			//ith element is removed from hashmap as it is used as nums[j] element specified in question (if it is used)
            m[nums[i]]--;
			
			//remove the element from hashmap inorder to get the right results when finding the upper bound
            if(m[nums[i]] == 0) m.erase(nums[i]);
			
			//we just have to look in the right side of the array for a number which follow's nums[k] criteria as specified in question
            if(nums[i] > mn)
            {
                auto el = m.upper_bound(mn);
                
                if(el != m.end() && el->first < nums[i]) return true;
            }
			//store minimum in mn traversed till now
            else 
            {
                mn = min(mn, nums[i]);
            }
        }
        return false;
    }
        
};