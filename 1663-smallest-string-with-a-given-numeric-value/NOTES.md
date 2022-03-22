Algorithm:
1. Initialize ans with n times 'a'
2. k=k-n
3. Iterate from right to left
while(k>0)
ans[idx]=min(25,k);
k-=min(25,k);
4. return ans