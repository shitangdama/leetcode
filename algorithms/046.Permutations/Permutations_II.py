<<<<<<< HEAD
# Time:  O(n!)
# Space: O(n)

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        result = []
        used = [False] * len(num)
        self.permuteRecu(result, used, [], num)
        return result
    
    def permuteRecu(self, result, used, cur, num):
        if len(cur) == len(num):
            result.append(cur + [])
            return
        for i in xrange(len(num)):
            if not used[i]:
                used[i] = True
                cur.append(num[i])
                self.permuteRecu(result, used, cur, num)
                cur.pop()
                used[i] = False

if __name__ == "__main__":
    print Solution().permute([1, 2, 3])
=======
# Time:  O(n!)
# Space: O(n)

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        result = []
        used = [False] * len(num)
        self.permuteRecu(result, used, [], num)
        return result
    
    def permuteRecu(self, result, used, cur, num):
        if len(cur) == len(num):
            result.append(cur + [])
            return
        for i in xrange(len(num)):
            if not used[i]:
                used[i] = True
                cur.append(num[i])
                self.permuteRecu(result, used, cur, num)
                cur.pop()
                used[i] = False

if __name__ == "__main__":
    print Solution().permute([1, 2, 3])
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
