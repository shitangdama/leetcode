public class Solution {
    public int[][] generateMatrix(int n) {
        if (n < 0) {
            return null;
        }

        int[][] result = new int[n][n];

        int xStart = 0;
        int yStart = 0;
        int num = 1;

        while (n > 0) {
            if (n == 1) {
                result[yStart][xStart] = num++;
                break;
            }

            for (int i = 0; i < n - 1; i++) {
                result[yStart][xStart + i] = num++;
            }

            for (int i = 0; i < n - 1; i++) {
                result[yStart + i][xStart + n - 1] = num++;
            }

            for (int i = 0; i < n - 1; i++) {
                result[yStart + n - 1][xStart + n - 1 - i] = num++;
            }

            for (int i = 0; i < n - 1; i++) {
                result[yStart + n - 1 - i][xStart] = num++;
            }

            xStart++;
            yStart++;
            n = n - 2;
        }

        return result;
    }
}

