class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        Dict = {}
        for i in range(len(nums)):
            if nums[i] in Dict:
                Dict[nums[i]] = Dict[nums[i]] + 1
            else:
                Dict[nums[i]] = 1

        output = sorted(Dict.items(),key=lambda e:e[1],reverse=True)

        final = []
        for i in range(k):
            final.append(output[i][0])
        return final