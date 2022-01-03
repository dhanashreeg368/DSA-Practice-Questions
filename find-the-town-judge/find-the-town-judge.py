class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        #solving this question using graphs
        trusting=[0]*(n+1)  #array for the people who trust
        trusted=[0]*(n+1)   #array for the people who do not trust (size n+1 because index start 1)
        for person1,person2 in trust:
            trusting[person1]-=1    #dec count for trusting
            trusted[person2]+=1 #inc count for being trusted 
        for i in range(1,n+1):
            if trusting[i]==0 and trusted[i]==n-1: #should not trust any and should be trusted by all
                return i
        return -1
                
        