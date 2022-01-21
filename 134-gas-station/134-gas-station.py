class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totalgas = 0
        totalcost = 0
        start = 0
        balance = 0
        for i in range(0, len(gas)):
            totalgas += gas[i]
            totalcost += cost[i]
            balance += gas[i] - cost[i]
            if balance < 0:
                start = i + 1
                balance = 0
        
        if totalcost <= totalgas:
            return start
        return -1
            

        