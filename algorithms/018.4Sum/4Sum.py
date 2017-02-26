class Solution2:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, nums, target):
        nums, result, lookup = sorted(nums), [], {}
        for i in range(0, len(nums) - 1):
            for j in range(i + 1, len(nums)): 
                if nums[i] + nums[j] not in lookup:
                    lookup[nums[i] + nums[j]] = []
                lookup[nums[i] + nums[j]].append([i, j])

        for i in lookup.keys():
            if target - i in lookup:
                for x in lookup[i]:
                    for y in lookup[target -i]:
                        [a, b], [c, d] = x, y
                        if a is not c and a is not d and b is not c and b is not d:
                            quad = sorted([nums[a], nums[b], nums[c], nums[d]])
                            if quad not in result:
                                result.append(quad)
        return sorted(result)
