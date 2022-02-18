class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        li_num=list(num)  #converting to list    
        while(k>0):
            i=0
            found=0 #flag to check if current is greater than (0: not greater)
            while(i<len(li_num)-1 and k>0):
                if int(li_num[i])>int(li_num[i+1]): #if current>next: del current
                    del li_num[i]
                    found=1 #(flag set to 1 means greater current is found)
                    k=k-1 #decrement k
                    break #iterate from start again
                i+=1

            if found==0: #if no greater is found eg.1234 (then remove last ele)
                while(k>0):          
                    li_num.pop()
                    k=k-1
        if(len(li_num)==0): #if string is empty
            return "0"
        ans=int(''.join(li_num)) #joining list elements as int
        return str(ans)
                
            
                
                
                
        
        