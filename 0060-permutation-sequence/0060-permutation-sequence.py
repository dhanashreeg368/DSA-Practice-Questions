class Solution:
    def getPermutation(self, n: int, k: int) -> str:
                # Initialize the numbers list
        numbers = list(range(1, n+1))
        # Initialize the result string
        result = []
        
        # Convert k to zero-based index
        k -= 1
        
        # Calculate the factorial for (n-1) down to 1
        for i in range(n, 0, -1):
            # Determine the index of the current digit
            fact = math.factorial(i - 1)
            index = k // fact
            k %= fact
            
            # Append the digit to the result and remove it from the list
            result.append(str(numbers[index]))
            numbers.pop(index)
        
        return ''.join(result)
        