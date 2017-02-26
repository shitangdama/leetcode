# Time:  O(n)
# Space: O(1)

class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        jump_count = 0
        reachable = 0
        curr_reachable = 0
        for i, length in enumerate(A):
            if i > reachable:
                return -1
            if i > curr_reachable:
                curr_reachable = reachable
                jump_count += 1
            reachable = max(reachable, i + length)
        return jump_count

# Time:  O(n^2)
# Space: O(1)     
class Solution2:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        result, prev_reachable, reachable = 0, -1, 0
        while reachable > prev_reachable:
            if reachable >= len(A) - 1:
                return result
            result += 1
            prev_reachable = reachable
            for i, length in enumerate(A[:reachable + 1]):
                reachable = max(reachable, i + length)
        return -1
    
if __name__ == "__main__":
    print Solution().jump([2,3,1,1,4])
    print Solution().jump([3,2,1,0,4])
