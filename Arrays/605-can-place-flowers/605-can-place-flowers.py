class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed = [0] + flowerbed + [0] 
        count, consecutiveZeros = 0, 0
        
        for flower in flowerbed:
            if flower == 0:
                consecutiveZeros += 1 
                if consecutiveZeros == 3:
                    count +=1
                    consecutiveZeros = 1
            else:
                consecutiveZeros = 0
                
        return n <= count
            
                