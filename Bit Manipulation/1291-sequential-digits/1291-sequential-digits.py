class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans=[]
        number='123456789'
        for i in range(len(number)):
            for j in range(i+1,len(number)):
                num=int(number[i:j+1])
                if (num>=low and num<=high):
                    ans.append(num)
        ans.sort()
        return ans
            

            
            
            
        