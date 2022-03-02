class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        answer = list(accumulate(differences, initial = 0))
        return max(0, (upper - lower) - (max(answer) - min(answer)) + 1)


            
            
            
            
        