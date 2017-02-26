<<<<<<< HEAD
public class Solution {
    static int[] dx = {1, 0, 0, -1};
    static int[] dy = {0, 1, -1, 0};
    private int n, m;
    
    private void removeIsland(char[][] grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if (grid[nextX][nextY] == '1') {
                    removeIsland(grid, nextX, nextY);
                }
            }
        }
    }
    
    public int numIslands(char[][] grid) {
        n = grid.length;
        if (n == 0) {
            return 0;
        }
        
        m = grid[0].length;
        if (m == 0) {
            return 0;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    removeIsland(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
=======
public class Solution {
    static int[] dx = {1, 0, 0, -1};
    static int[] dy = {0, 1, -1, 0};
    private int n, m;
    
    private void removeIsland(char[][] grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if (grid[nextX][nextY] == '1') {
                    removeIsland(grid, nextX, nextY);
                }
            }
        }
    }
    
    public int numIslands(char[][] grid) {
        n = grid.length;
        if (n == 0) {
            return 0;
        }
        
        m = grid[0].length;
        if (m == 0) {
            return 0;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    removeIsland(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}