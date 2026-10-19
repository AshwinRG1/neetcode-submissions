class TimeMap:

    def __init__(self):
        self.timeMap = defaultdict(list)
        self.maxTime = 0

    def set(self, key: str, value: str, timestamp: int) -> None:
        timeMap[key].append([value, timestamp])
        maxTime = max(timestamp, maxTime)

    def get(self, key: str, timestamp: int) -> str:
        low = 0
        high = maxTime
        if timestamp == high:
            return timeMap[key][1]
        if timestamp == low:
            return timeMap[key][1]
        while low <= high:
            mid = (low + high) // 2
            if mid == timestamp:
                return timeMap[key][1]
            elif timestamp > mid:
                low = mid + 1
            else:
                high = mid -1
