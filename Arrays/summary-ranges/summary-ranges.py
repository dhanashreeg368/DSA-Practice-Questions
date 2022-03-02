class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        summary = []
        if len(nums) > 1:
            for i in range(len(nums)-1):
                if i == 0:
                    start = nums[0]
                    end = nums[0]
                if nums[i+1] == end+1:
                    end = end+1
                else:
                    if start!=end:
                        summary.append(str(start)+"->"+str(end))
                    else:
                        summary.append(str(start))
                    start = nums[i+1]
                    end = nums[i+1]
            if start!=end:
                summary.append(str(start)+"->"+str(end))
            else:
                summary.append(str(start))
        if len(nums) == 1:
            summary.append(str(nums[0]))
        return summary
        