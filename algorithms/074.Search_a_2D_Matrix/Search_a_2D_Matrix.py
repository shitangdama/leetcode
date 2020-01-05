class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):

        if len(matrix) == 0:
            return False
        m = len(matrix)
        n = len(matrix[0])
        i, j = 0, m * n

        while i < j:
            mid = i + int((j - i) / 2)
            val = matrix[int(mid / n)][mid % n]
            if val == target:
                return True
            elif val < target:
                i = mid + 1
            else:
                j = mid
        return False

if __name__ == "__main__":
    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
    print(Solution().searchMatrix(matrix, 3))
