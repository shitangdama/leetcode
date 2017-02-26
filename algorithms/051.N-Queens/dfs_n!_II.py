# Time:  O(n!)
# Space: O(n)

# quick solution for checking if it is diagonally legal
class Solution:
    # @return an integer
    def solveNQueens(self, n):
        self.cols = [False] * n
        self.main_diag = [False] * (2 * n)
        self.anti_diag = [False] * (2 * n)
        self.solutions = []
        self.solveNQueensRecu([], 0, n)
        return self.solutions

    
    def solveNQueensRecu(self, solution, row, n):
        if row == n:
            self.solutions.append(map(lambda x: '.' * x + "Q" + '.' * (n - x - 1), solution))
        else:
            for i in xrange(n):
                if not self.cols[i] and not self.main_diag[row + i] and not self.anti_diag[row - i + n]:
                    self.cols[i] = self.main_diag[row + i] = self.anti_diag[row - i + n] = True
                    self.solveNQueensRecu(solution + [i], row + 1, n)
                    self.cols[i] = self.main_diag[row + i] = self.anti_diag[row - i + n] = False

# slower solution
class Solution2:
    # @return an integer
    def solveNQueens(self, n):
        self.solutions = []
        self.solveNQueensRecu([], 0, n)
        return self.solutions
    
    def solveNQueensRecu(self, solution, row, n):
        if row == n:
            self.solutions.append(map(lambda x: '.' * x + "Q" + '.' * (n - x - 1), solution))
        else:
            for i in xrange(n):
                if i not in solution and reduce(lambda acc, j: abs(row - j) != abs(i - solution[j]) and acc, xrange(len(solution)), True):
                    self.solveNQueensRecu(solution + [i], row + 1, n)

if __name__ == "__main__":
    print Solution().solveNQueens(8)
