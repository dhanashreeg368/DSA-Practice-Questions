class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        if len(cost)==2:
            return cost[0]+cost[1]
        cost.sort(reverse=True)
        amt=0
        i=0
        while(i<len(cost)):
            if (i<len(cost)):
                amt+=cost[i]
            i+=1
            if (i<len(cost)):
                amt+=cost[i]
            i+=2
        return amt
            
        
        
        