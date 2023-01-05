class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        res, curStart = 1, points[-1][0]
        for start,end in reversed(points):
            if end<curStart:
                curStart = start
                res += 1
        return res
        