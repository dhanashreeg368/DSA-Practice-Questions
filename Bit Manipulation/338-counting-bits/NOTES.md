This question can be solved using Dynamic Programming
​
Eg. For n=5
We will return an array of n+1 length
Algorithm:
Use for loop to iterate from 0 to n+1
for every i
if i is odd, ans=l[i//2]+1
if i is even, ans=l[i//2]
Hence we will be using DP here
i=0, l[0]=0
i=1, l[1]=l[1/2]+1=1
i=2, l[2]=l[2/2]=1
l=3, l[3]=l[3/2]+1=1+1=2
i=4, l[4]=l[4/2]=2=2
i=5, l[5]=l[5/2]+1=2+1=3
​
ans=[0,1,1,2,2,3]
​