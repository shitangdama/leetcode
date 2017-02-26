<<<<<<< HEAD
# Time:  O(m * n)
# Space: O(1)

class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        first_col = reduce(lambda acc, i: acc or matrix[i][0] == 0, xrange(len(matrix)), False)
        first_row = reduce(lambda acc, j: acc or matrix[0][j] == 0, xrange(len(matrix[0])), False)
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0], matrix[0][j] = 0, 0
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if first_col:
            for i in xrange(len(matrix)):
                matrix[i][0] = 0
                
        if first_row:
            for j in xrange(len(matrix[0])):
                matrix[0][j] = 0

if __name__ == "__main__":
    matrix = [ [1, 0, 1, 1]
             , [1, 1, 0, 1]
             , [1, 1, 1, 0]
             , [1, 1, 1, 1]]
    Solution().setZeroes(matrix)
    print matrix
=======
# Time:  O(m * n)
# Space: O(1)

class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        first_col = reduce(lambda acc, i: acc or matrix[i][0] == 0, xrange(len(matrix)), False)
        first_row = reduce(lambda acc, j: acc or matrix[0][j] == 0, xrange(len(matrix[0])), False)
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0], matrix[0][j] = 0, 0
        
        for i in xrange(1, len(matrix)):
            for j in xrange(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if first_col:
            for i in xrange(len(matrix)):
                matrix[i][0] = 0
                
        if first_row:
            for j in xrange(len(matrix[0])):
                matrix[0][j] = 0

if __name__ == "__main__":
    matrix = [ [1, 0, 1, 1]
             , [1, 1, 0, 1]
             , [1, 1, 1, 0]
             , [1, 1, 1, 1]]
    Solution().setZeroes(matrix)
    print matrix
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
