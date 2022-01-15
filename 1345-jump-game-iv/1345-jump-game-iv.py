class Solution:
    def minJumps(self, arr: List[int]) -> int: 
        if len(arr) == 1: 
            return 0 
        if arr[0] == arr[len(arr) -1]: 
            return 1 
        
        q = deque([0])
        cnt = 0
        n = len(arr)
        dic = collections.defaultdict(list)
        
        for i, num in enumerate(arr): 
            dic[num].append(i)
        
        while q:
            for i in range(len(q)):
                x = q.popleft()
                if x == n-1:
                    return cnt

                if x-1 >=0 and x-1 in dic[arr[x-1]]:
                    q.append(x-1)
                    dic[arr[x-1]].remove(x-1)
                    
                if x+1 <= n-1 and x+1 in dic[arr[x+1]]:
                    q.append(x+1)
                    dic[arr[x+1]].remove(x+1)
                for j in dic[arr[x]]:
                    q.append(j)
                    
                del dic[arr[x]]
            cnt += 1
        return cnt

        
        