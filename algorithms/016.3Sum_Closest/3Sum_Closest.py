# 类似于上一题
class Solution:
    # @return an integer
    def threeSumClosest(self, nums, target):
        nums = sorted(nums)
        # 先定义几个变量
        # 最小差距
        min_diff = float("inf")
        # 结果
        result = float("inf")
        # 三个指针
        i, j, k = 0, 1, len(nums)-1
        while i < len(nums)-2:
            # 从新赋值
            j = i+1
            k = len(nums)-1
            while j<k:
                # 判断有几种情况
                diff = nums[i] + nums[j] + nums[k] - target
                if abs(diff) < min_diff:
                    min_diff = abs(diff)
                    result = nums[i] + nums[j] + nums[k]
                if diff < 0:
                    j = j+1
                elif diff > 0:
                    k = k-1
                else:
                    print(nums[i], nums[j], nums[k])
                    return result
            
            i += 1
            while  i < len(nums) - 2 and nums[i] == nums[i-1]:
                i = i+1
        return result

s = Solution()
a = s.threeSumClosest([1,1,-1,-1,3], -1)
print(a)
