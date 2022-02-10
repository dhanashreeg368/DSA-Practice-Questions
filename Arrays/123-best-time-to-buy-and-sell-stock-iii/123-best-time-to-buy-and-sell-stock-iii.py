class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        fb=inf
        sb=inf
        fs=0
        ss=0
        for i in range(len(prices)):
            fb=min(fb,prices[i])
            fs=max(fs,prices[i]-fb)
            sb=min(sb,prices[i]-fs)
            ss=max(ss,prices[i]-sb)
        return ss
            
            
            
        