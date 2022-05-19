class Solution:
    from functools import lru_cache
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        
        self.height = len(matrix)
        self.width = len(matrix[0])
        self.grid = matrix
        
        return max([self.dfs(x, y) for x in range(self.height) for y in range(self.width)])
        
        
    
    @lru_cache(maxsize = None)
    def dfs(self, x, y, distance = 1):
        
        new_dist = distance
        
        for x_del, y_del in [(-1,0) , (0,1) , (1,0) , (0,-1)]:
            x_new, y_new = x+x_del, y+y_del
            
            if 0 <= x_new < self.height and 0 <= y_new <self.width and self.grid[x_new][y_new] > self.grid[x][y]:

                new_dist = max(new_dist, distance + self.dfs(x_new, y_new, distance))
             
        return new_dist