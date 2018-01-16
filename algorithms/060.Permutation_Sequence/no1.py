# 碾压相除法

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # math.factorial
        # 阶乘
        nums = list(range(1,n+1))
        result = ""
        k = k-1
        for i in range(n,0,-1):
            tmp = int(k/self.factorial(i-1))
            k = k%self.factorial(i-1)
            result = result + str(nums[tmp])
            nums.remove(nums[tmp])
        return result

    def factorial(self, n):
        tmp = 1
        for i in range(n):
            tmp = tmp *(i+1)
        return tmp

s = Solution()
a = s.getPermutation(3,4)
print(a)