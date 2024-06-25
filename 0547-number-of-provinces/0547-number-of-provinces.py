class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(city):
            # Mark the city as visited
            visited[city] = True
            # Visit all the connected cities
            for neighbor, is_connected in enumerate(isConnected[city]):
                if is_connected and not visited[neighbor]:
                    dfs(neighbor)
        
        n = len(isConnected)
        visited = [False] * n
        num_provinces = 0
        
        for city in range(n):
            if not visited[city]:
                # If the city is not visited, start a DFS and count a new province
                dfs(city)
                num_provinces += 1
        
        return num_provinces
        