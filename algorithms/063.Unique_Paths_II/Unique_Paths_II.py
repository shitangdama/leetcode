# Time:  O(m * n)
# Space: O(m + n)

class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        ways = [0] * n
        
        if obstacleGrid[0][0] == 0:
            ways[0] = 1
            
        for j in xrange(1, n):
            if obstacleGrid[0][j] == 1:
                ways[j] = 0
            else:
                ways[j] = ways[j - 1]
        
        for i in xrange(1, m):
            if obstacleGrid[i][0] == 1:
                ways[0] = 0
                
            for j in xrange(1, n):
                if obstacleGrid[i][j] == 1:
                    ways[j] = 0
                else:
                    ways[j] += ways[j - 1]
        
        return ways[n - 1]

if __name__ == "__main__":
    obstacleGrid = [
                      [0,0,0],
                      [0,1,0],
                      [0,0,0]
                   ]
    print Solution().uniquePathsWithObstacles(obstacleGrid)
