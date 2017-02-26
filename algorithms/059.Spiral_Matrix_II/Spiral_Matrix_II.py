<<<<<<< HEAD
# Time:  O(n^2)
# Space: O(1)

class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        matrix = [[0 for i in range(n)] for i in range(n)]
        
        left, right, top, bottom, num = 0, n - 1, 0, n - 1, 1
        
        while left <= right and top <= bottom:
            for j in xrange(left, right + 1):
                matrix[top][j] = num
                num += 1
            for i in xrange(top + 1, bottom):
                matrix[i][right] = num
                num += 1
            for j in reversed(xrange(left, right + 1)):
                if top < bottom:
                    matrix[bottom][j] = num
                    num += 1
            for i in reversed(xrange(top + 1, bottom)):
                if left < right:
                    matrix[i][left] = num
                    num += 1
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
            
        return matrix


if __name__ == "__main__":
    print Solution().generateMatrix(3)
    print Solution().generateMatrix(8)

=======
# Time:  O(n^2)
# Space: O(1)

class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        matrix = [[0 for i in range(n)] for i in range(n)]
        
        left, right, top, bottom, num = 0, n - 1, 0, n - 1, 1
        
        while left <= right and top <= bottom:
            for j in xrange(left, right + 1):
                matrix[top][j] = num
                num += 1
            for i in xrange(top + 1, bottom):
                matrix[i][right] = num
                num += 1
            for j in reversed(xrange(left, right + 1)):
                if top < bottom:
                    matrix[bottom][j] = num
                    num += 1
            for i in reversed(xrange(top + 1, bottom)):
                if left < right:
                    matrix[i][left] = num
                    num += 1
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1
            
        return matrix


if __name__ == "__main__":
    print Solution().generateMatrix(3)
    print Solution().generateMatrix(8)

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
