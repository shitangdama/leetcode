# 有问题应该在

import math

class Solution:
    def permuteUnique(self, num):
        result = []
        for n in range(self.factorial(num)):
            self.next(num)
            # print(num)
            result.append(list(num))
        return result

    def next(self,num):
        k = -1
        for i in range(len(num)-2, -1, -1):
            if num[i] < num[i+1]:
                k = i
                break

        if k == -1:
            self.reverse(num , 0, len(num)-1)
            return
        l = -1
        for i in range(len(num)-1, k, -1):
            if num[i] > num[k]:
                l = i
                break

        num[l], num[k] = num[k], num[l]
        self.reverse(num,k+1,len(num)-1)

    def reverse(self, num, l, r):
        while l < r:
            num[l],num[r] = num[r],num[l]
            l += 1
            r -= 1
    # 在这个地方要做限制
    def factorial(self, num):
        tmp = 1
        for i in range(len(num)):
            if i > 0 and num[i-1] == num[i]:
                continue
            tmp = tmp *(i+1)
        print(tmp)
        return tmp

s = Solution()
print(s.permuteUnique([1,1,2,2]))
