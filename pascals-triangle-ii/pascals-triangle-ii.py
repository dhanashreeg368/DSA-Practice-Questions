class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        cur = [1]
        for i in range(1,rowIndex+1):
            new_row = [1]
            for j in range(1,i):
                new_row.append(cur[j-1]+cur[j])
            new_row.append(1)
            cur=new_row
        return cur
            
        