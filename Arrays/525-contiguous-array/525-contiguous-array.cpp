class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int cnt;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
           sum += (nums[i]==0)?-1:1;  
           auto it = m.find(sum);       
           if(sum == 0){
              if(cnt < i+1)
               cnt = i+1;
           }
           else if(it != m.end()){
              if(cnt < i-it->second)
               cnt = i-it->second;
           }
           else if(it == m.end())
                m.insert({sum,i});
       }
        return cnt;
    }
};