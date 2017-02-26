<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

class Solution:
    # @return an integer
    def maxArea(self, height):
        max_area, i, j = 0, 0, len(height) - 1
        while i < j:
            max_area = max(max_area, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max_area
    

=======
# Time:  O(n)
# Space: O(1)

class Solution:
    # @return an integer
    def maxArea(self, height):
        max_area, i, j = 0, 0, len(height) - 1
        while i < j:
            max_area = max(max_area, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max_area
    
if __name__ == "__main__":
    height = [1, 2, 3, 4, 3, 2, 1, 5]
    result = Solution().maxArea(height)
    print result
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
