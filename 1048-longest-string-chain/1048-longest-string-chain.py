class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        wordSet = set(words)

        @lru_cache(None)
        def dp(word):
            ans = 1
            for i in range(len(word)):
                predecessor = word[:i] + word[i + 1:]
                if predecessor in wordSet:
                    ans = max(ans, dp(predecessor) + 1)
            return ans

        return max(dp(w) for w in words)
        