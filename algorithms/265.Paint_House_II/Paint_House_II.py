import heapq

class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
            return 0
        values = costs[0][:]
        k = len(values)
        heap = [(values[i], i) for i in range(k)]
        heapq.heapify(heap)
        for i in range(1, len(costs)):
            # find two smallest numbers in values array
            smallest_value, smallest_ind = heapq.heappop(heap)
            secondsmallest = heapq.heappop(heap)[0]
            values = [costs[i][j] + smallest_value for j in range(k)]
            values[smallest_ind] += secondsmallest - smallest_value
            heap = [(values[i], i) for i in range(k)]
            heapq.heapify(heap)
        return min(values)
