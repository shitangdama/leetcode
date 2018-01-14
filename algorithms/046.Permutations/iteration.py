# Time:  O(n!)
# Space: O(n)
import math

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        result = []
        for n in range(math.factorial(len(num))):
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
            num.reverse()
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

    def factorial(self, n):
        tmp = 1
        for i in n:
            tmp = tmp *(i+1)
        return tmp

s = Solution()
print(s.permute([1,2,3]))
