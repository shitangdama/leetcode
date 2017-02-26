public class Solution {
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0) {
            return 0;
        }

        int h = costs.length;
        int w = costs[0].length;

        int[][] map = new int[h + 1][w];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                map[i + 1][j] = Integer.MAX_VALUE;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < w; k++) {
                    if (j != k) {
                        map[i + 1][j] = Math.min(map[i + 1][j], map[i][k] + costs[i][j]);
                    }
                }
            }
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < w; i++) {
            result = Math.min(result, map[h][i]);
        }
        return result;
    }
}