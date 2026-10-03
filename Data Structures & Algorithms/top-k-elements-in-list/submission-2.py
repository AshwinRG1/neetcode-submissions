class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        freqs = {}
        for num in nums:
            if num in freqs:
                freqs[num] += 1
            else:
                freqs[num] = 1

        heap =[]
        for num in freqs.keys():
            heapq.heappush(heap, (freqs[num],num))
            if len(heap) > k:
                heapq.heappop(heap)
        
        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1])
        
        return res