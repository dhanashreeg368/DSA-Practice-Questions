This is very simple question which can be solved using loops.
​
What we need to do?
We need all the elements in increasing order from left to right after removing k elements.
​
How can we do it?
Simple Intuition here:
STEPS:
1. Convert string to list. Becomes easy for iterating.
2. Take flag=0 (Sets if current>next, initially zero)
3. While iterating in the list till last element (while k>0)
if current ele>next ele:
del current ele
decrement k
flag=1
break
4. If after iterating the list all elements are in increasing order from left to right then we will remove the last k elements.
Eg. num="1234", k=2
Remove last 2 elements
if found==0: #if no greater is found
while(k>0):
li_num.pop()
k=k-1
5. If string is empty return 0
if(len(li_num)==0):
return "0"