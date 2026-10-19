class TimeMap:

    def __init__(self):
        self.timeMap = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.timeMap[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        values = self.timeMap[key]
        low = 0
        high = len(values) - 1
        while low <= high:
            mid = (low + high) // 2
            if values[mid][1] == timestamp:
                return values[mid][0]
            elif timestamp > values[mid][1]:
                res = values[mid][0]
                low = mid + 1
            else:
                high = mid - 1
        return ""