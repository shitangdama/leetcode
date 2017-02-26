# Time:  O(n^2)
# Space: O(n)

class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        for i in xrange(9):
            if not self.isValidList([board[i][j] for j in xrange(9)]) or not self.isValidList([board[j][i] for j in xrange(9)]):
                return False
        for i in xrange(3):
            for j in xrange(3):
                if not self.isValidList([board[m][n] for n in xrange(3 * j, 3 * j + 3) for m in xrange(3 * i, 3 * i + 3)]):
                    return False
        return True
    
    def isValidList(self, xs):
        xs = filter(lambda x: x != '.', xs)
        return len(set(xs)) == len(xs)

if __name__ == "__main__":
    board = [[1, '.', '.', '.', '.', '.', '.', '.', '.'],
             ['.', 2, '.', '.', '.', '.', '.', '.', '.'],
             ['.', '.', 3, '.', '.', '.', '.', '.', '.'],
             ['.', '.', '.', 4, '.', '.', '.', '.', '.'],
             ['.', '.', '.', '.', 5, '.', '.', '.', '.'],
             ['.', '.', '.', '.', '.', 6, '.', '.', '.'],
             ['.', '.', '.', '.', '.', '.', 7, '.', '.'],
             ['.', '.', '.', '.', '.', '.', '.', 8, '.'],
             ['.', '.', '.', '.', '.', '.', '.', '.', 9]]
    print Solution().isValidSudoku(board)
