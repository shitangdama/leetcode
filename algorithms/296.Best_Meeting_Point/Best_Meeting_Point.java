<<<<<<< HEAD
public class Solution {
    public int minTotalDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] row_sum = new int[n], col_sum = new int[m];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                row_sum[j] += grid[i][j];
                col_sum[i] += grid[i][j];
            }

        return minDistance1D(row_sum) + minDistance1D(col_sum);
    }

    public int minDistance1D(int[] vector) {
        int i = -1, j = vector.length;
        int d = 0, left = 0, right = 0;

        while (i != j) {
            if (left < right) {
                d += left;
                left += vector[++i];
            }
            else {
                d += right;
                right += vector[--j];
            }
        }
        return d;
    }

=======
public class Solution {
    public int minTotalDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] row_sum = new int[n], col_sum = new int[m];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                row_sum[j] += grid[i][j];
                col_sum[i] += grid[i][j];
            }

        return minDistance1D(row_sum) + minDistance1D(col_sum);
    }

    public int minDistance1D(int[] vector) {
        int i = -1, j = vector.length;
        int d = 0, left = 0, right = 0;

        while (i != j) {
            if (left < right) {
                d += left;
                left += vector[++i];
            }
            else {
                d += right;
                right += vector[--j];
            }
        }
        return d;
    }

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}