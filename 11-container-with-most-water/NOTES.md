**Intuition**
​
We will start storing water from minimum height first. And eventually we will start storing at max height.
So taking 2 pointers, start and end to check height and find area.
​
Algorithm:
1. Initialise i and j=height.size()-1
2. mx=max(mx,min(height[i],height[j])*(j-i))
3. If i is less: then increment
4. else dec j