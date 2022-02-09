class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0: 
            return 0
        res, lookup = set(), set()
        for num in nums:
            if num-k in lookup:
                res.add(num-k)
            if num+k in lookup:
                res.add(num)
            lookup.add(num)
        return len(res)
        
        