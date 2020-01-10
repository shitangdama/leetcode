# Time:  O(m * n)
# Space: O(m + n)

class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):

        sum = [[0]*len(grid[0]) for _ in range(len(grid))]

        sum[0][0] = grid[0][0]

        for i in range(1, len(grid[0])):
            sum[0][i] = sum[0][i-1] + grid[0][i]


        for j in range(1, len(grid)):
            sum[j][0] = sum[j-1][0] + grid[j][0]


        for j in range(1, len(grid)):
            for i in range(1, len(grid[0])):
                sum[j][i] = min(sum[j][i-1], sum[j-1][i])+ grid[j][i]

        return sum[-1][-1]


if __name__ == "__main__":

    print(Solution().minPathSum([[1,2,5],[3,2,1]]))
    # print(Solution().minPathSum([[1,3,1],[1,5,1],[4,2,1]]))
