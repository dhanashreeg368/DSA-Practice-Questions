class Solution:
    def reverseWords(self, s: str) -> str:
        #if(s[0]==' ' and len(s)-1==' '):
            
        #s.strip(' ')
        print(s)
        li=s.split()
        n=len(li)
        i=0
        temp=""
        print(li)
        start=0
        end=n-1
        while(start<=end):
            temp=li[start]
            li[start]=li[end]
            li[end]=temp
            start+=1
            end-=1
        print(li)
        x = " ".join(li)
        return x.strip()
        
        
        