class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
         int n = stations.size();
        int count = 0;
        int distLimit = startFuel;
        int maxDist = 0;
        
        if(startFuel >= target)
            return 0;
        else if(!n)
            return -1;
        
        int k = 0;

        priority_queue<int> max_pq;
        while(k < n)
        {
            while(k < n && stations[k][0] <= distLimit)
            {              
                max_pq.push(stations[k][1]);
                k++;
            }
            
            if(max_pq.empty())
               break;
        
            while(!max_pq.empty())
            {
                count++;
                distLimit += max_pq.top();
                max_pq.pop();
    
                if(distLimit >= target)
                    return count;
                
               if(k < n && distLimit >= stations[k][0])
                    break;                
            }
    
            if( k >= n)
                break;
        }
        
       return -1;
        
    }
    // Time O(NlogN)
    // Space O(N)
};