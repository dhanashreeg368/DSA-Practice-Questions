class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        # Mapping from digits to corresponding letters
        phone_map = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }

        # List to hold the result combinations
        result = []

        # Backtracking function
        def backtrack(index, current_combination):
            # If the current combination is complete
            if index == len(digits):
                result.append(current_combination)
                return
            
            # Get the letters that the current digit can represent
            current_digit = digits[index]
            for letter in phone_map[current_digit]:
                # Append the current letter and move to the next digit
                backtrack(index + 1, current_combination + letter)

        # Start the backtracking with the initial index and empty combination
        backtrack(0, "")
        
        return result
        