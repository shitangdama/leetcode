class Solution:
    # @param {boolean[][]} grid a boolean 2D matrix
    # @return {int} an integer
    def numIslands(self, grid):
        if not grid:
            return 0
    
        row = len(grid)
        col = len(grid[0])
        used = [[False for j in xrange(col)] for i in xrange(row)]
    
        count = 0
        for i in xrange(row):
            for j in xrange(col):
                if grid[i][j] == '1' and not used[i][j]:
                    self.dfs(grid, used, row, col, i, j)
                    count += 1
        return count

    def dfs(self, grid, used, row, col, x, y):
        if grid[x][y] == '0' or used[x][y]:
            return
        used[x][y] = True
    
        if x != 0:
            self.dfs(grid, used, row, col, x - 1, y)
        if x != row - 1:
            self.dfs(grid, used, row, col, x + 1, y)
        if y != 0:
            self.dfs(grid, used, row, col, x, y - 1)
        if y != col - 1:
            self.dfs(grid, used, row, col, x, y + 1)

