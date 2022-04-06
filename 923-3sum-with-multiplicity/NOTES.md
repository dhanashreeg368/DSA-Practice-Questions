APPROACH :
​
We traverse the array using 2 loops & compute the sums of all possible pairs.
​
We store the sums of pairs in an unordered_map along with their frequency.
​
While traversing, we also check if the target - current element is present in the map. If so, we add it's frequency to the result.
​
Finally we return the result.
​
Time Complexity : O(n)
​
Space Complexity : O(2^n)