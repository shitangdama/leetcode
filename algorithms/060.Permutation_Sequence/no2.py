class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        numbers = list(range(1, n+1))

        tmp = self.factorial(n)
        time = k%tmp
        for n in range(k-1):    
            self.next(numbers)
        result = ""
        for i in numbers:
            result = result + str(i)

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
    def factorial(self, n):
        tmp = 1
        for i in range(n):
            tmp = tmp *(i+1)
        return tmp

s =Solution()
a = s.getPermutation(2,1)
print(a)