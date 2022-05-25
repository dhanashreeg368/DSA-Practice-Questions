class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        
        res = []		
		# Perform LIS
        for _, h in envelopes:
            l,r=0,len(res)-1
			# find the insertion point in the Sort order
            while l <= r:
                mid=(l+r)>>1
                if res[mid]>=h:
                    r=mid-1
                else:
                    l=mid+1        
            idx = l
            if idx == len(res):
                res.append(h)
            else:
                res[idx]=h
        return len(res)
        