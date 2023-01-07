class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        diff = list(accumulate([g - c for g,c in zip(gas,cost)], initial = 0))

        return diff.index(min(diff)) if diff[-1] >= 0 else -1
        