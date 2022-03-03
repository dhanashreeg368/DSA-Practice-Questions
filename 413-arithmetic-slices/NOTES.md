EXPLANATION
​
The Idea is Simple , the array is called arithmetic if it consists of at least 3 elements.
So, firstly if arr_size is < 3 , we will return false.
The second requirement of the question is, that the difference b/w any two consecutive elements should be same.
Storing diff of first 2 elements in diff as prev_diff = nums[1] - nums[0].
Now iterating a loop from i = 1 to nums.size()-1 and finding the diff of next consecutive elements.
If the diff is equal to prev_diff, increase the cnt of ind variable;
else set ind to zero and update prev_diff with curr diff.
add ind to cnt.
Return cnt.
TIME COMPLEXITY
O(N)
​
SPACE COMPLEXITY
O(1)
​