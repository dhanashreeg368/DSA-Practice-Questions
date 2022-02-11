class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // Suppose sum_i represents the running sum starting from index 0 and ending at i
        // once we find a mod that has been seen, say modk, we have:
        
        // current one: sum_i = m*k + modk
        // previous one: sum_j = n*k + modk
        // Thus,
        // sum_i - sum_j = (m - n) *k
        
        int n=nums.size();
        if (n<2)
        {
            return false;
        }
    
        //Create a hashmap of the running_sum remainder and it's respective index
        unordered_map<int,int> mp;  //declare map to store values
        mp[0]=-1; //<0,-1> can allow it to return true when the runningSum%k=0,
        
        int runningSum=0;
        
        for(int i=0;i<n;i++)
        {
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            //check if the runningsum already exists in the hashmap
            if(mp.find(runningSum)!=mp.end())
            {
            //if it exists, then the current location minus the previous location must be greater than1
                
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
            {
            //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                
                mp[runningSum]=i;
            }
                    
        }
        
        return false;
        
    }
    
};