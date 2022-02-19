class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set <int> s; //for storing elements in order
        //here we are making all even - so make all odds as even
        //using only even operation
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0) //if even:insert
            {
                s.insert(nums[i]);
            }
            else //if odd-convert then insert
            {
                s.insert(nums[i]*2); //converting to even
            }
        }
        int diff=*s.rbegin()-*s.begin();
        while(*s.rbegin()%2==0) //iterate while we not get odd number
        {
            int maxx=*s.rbegin(); //will store max value
            s.erase(maxx); //remove max and put its half value
            s.insert(maxx/2); 
            diff=min(diff,*s.rbegin()-*s.begin());
        }
        return diff;
    }
};