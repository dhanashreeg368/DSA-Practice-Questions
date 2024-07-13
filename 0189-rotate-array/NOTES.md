​
To rotate an array to the right by k steps, we can use a more efficient approach than rotating the array one step at a time. The optimal approach involves reversing parts of the array. This solution has 𝑂(𝑛) time complexity and O(1) space complexity.
​
**Approach**
1. Reverse entire array
2. Reverse first k elements
3. Revervse remaining n-k elements
​
**Edge case:**
What if k>n?
Then k=k%n;