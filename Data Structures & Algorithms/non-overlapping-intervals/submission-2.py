class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[0])

        res = [intervals[0]]

        size = len(intervals)
        
        for i in range(1, size):
            if (intervals[i][0] >= res[-1][1]):
                res.append(intervals[i])
        return size - len(res)