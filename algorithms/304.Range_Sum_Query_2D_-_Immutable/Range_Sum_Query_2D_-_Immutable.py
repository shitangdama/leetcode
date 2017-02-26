class NumMatrix(object):
      def __init__(self, matrix):
          if matrix is None or not matrix:
              return
          n, m = len(matrix), len(matrix[0])
          self.sums = [ [0 for j in xrange(m+1)] for i in xrange(n+1) ]
          for i in xrange(1, n+1):
              for j in xrange(1, m+1):
                  self.sums[i][j] = matrix[i-1][j-1] + self.sums[i][j-1] + self.sums[i-1][j] - self.sums[i-1][j-1]


      def sumRegion(self, row1, col1, row2, col2):
          row1, col1, row2, col2 = row1+1, col1+1, row2+1, col2+1
          return self.sums[row2][col2] - self.sums[row2][col1-1] - self.sums[row1-1][col2] + self.sums[row1-1][col1-1]
