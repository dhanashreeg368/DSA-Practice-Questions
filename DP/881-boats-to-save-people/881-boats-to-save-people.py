class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        low=0
        ans=0
        high=len(people)-1
        while(high>=low):
            if (people[low]+people[high]<=limit):
                low+=1
            high-=1
            ans+=1
        return ans
        