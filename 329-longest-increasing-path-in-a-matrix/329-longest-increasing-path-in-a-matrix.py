class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        longest_by_pos={}
        deltas=[(1,0),(-1,0),(0,1),(0,-1)]
        ROWS,COLS = len(matrix),len(matrix[0])
        
        def dfs(pos):
            if pos in longest_by_pos:
                return longest_by_pos[pos]
            
            val=matrix[pos[0]][pos[1]]
            longest=1
            for delta_x,delta_y in deltas:
                neighbor_x=delta_x+pos[0]
                neighbor_y=delta_y+pos[1]
                
                if 0<=neighbor_x<ROWS and 0<=neighbor_y<COLS and matrix[neighbor_x][neighbor_y]>val:
                    longest=max(longest,1+dfs((neighbor_x,neighbor_y)))
            
            longest_by_pos[pos]=longest
            return longest
        
        max_path=1
        for row in range(ROWS):
            for col in range(COLS):
                max_path=max(max_path,dfs((row,col)))
        return max_path