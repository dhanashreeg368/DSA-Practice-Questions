class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        ls=[]
        for n, start, end in trips:
            ls.append((start,n))
            ls.append((end,-n))
        ls.sort()
        par=0
        for i in ls:
            par+=i[1]
            if par> capacity:
                return False
        return True
        