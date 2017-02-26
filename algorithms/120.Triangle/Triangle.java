<<<<<<< HEAD
//Version 1: Bottom-Up
public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        int n = triangle.size();
        int[][] sum = new int[n][n];

        for (int i = 0; i < n; i++) {
            sum[n - 1][i] = triangle.get(n - 1).get(i);
        }

        for (int i = n - 2; i >= 0; i--) { 
            for (int j = 0; j <= i; j++) {
                sum[i][j] = Math.min(sum[i + 1][j], sum[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }

        return sum[0][0];
    }
}


//Version 2 : Memorize Search
public class Solution {
    private int n;
    private int[][] minSum;
    private ArrayList<ArrayList<Integer>> triangle;

    private int search(int x, int y) {
        if (x >= n) {
            return 0;
        }

        if (minSum[x][y] != Integer.MAX_VALUE) {
            return minSum[x][y];
        }

        minSum[x][y] = Math.min(search(x + 1, y), search(x + 1, y + 1))
            + triangle.get(x).get(y);
        return minSum[x][y];
    }

    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        this.n = triangle.size();
        this.triangle = triangle;
        this.minSum = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minSum[i][j] = Integer.MAX_VALUE;
            }
        }

        return search(0, 0);
    }
} 


//Version 3 : (Time Limit Exceed) Up-Bottom Update
public class Solution {
    private int n;
    private int[][] minSum;
    private ArrayList<ArrayList<Integer>> triangle;

    private void search(int x, int y, int sum) {
        if (x >= n) {
            return;
        }
        if (sum + triangle.get(x).get(y) >= minSum[x][y]) {
            return;
        }
        minSum[x][y] = sum + triangle.get(x).get(y);

        search(x + 1, y, minSum[x][y]);
        search(x + 1, y + 1, minSum[x][y]);
    }

    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        this.n = triangle.size();
        this.triangle = triangle;
        this.minSum = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minSum[i][j] = Integer.MAX_VALUE;
            }
        }

        search(0, 0, 0);

        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            answer = Math.min(answer, minSum[n-1][i]);
        }
        return answer;
    }
=======
//Version 1: Bottom-Up
public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        int n = triangle.size();
        int[][] sum = new int[n][n];

        for (int i = 0; i < n; i++) {
            sum[n - 1][i] = triangle.get(n - 1).get(i);
        }

        for (int i = n - 2; i >= 0; i--) { 
            for (int j = 0; j <= i; j++) {
                sum[i][j] = Math.min(sum[i + 1][j], sum[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }

        return sum[0][0];
    }
}


//Version 2 : Memorize Search
public class Solution {
    private int n;
    private int[][] minSum;
    private ArrayList<ArrayList<Integer>> triangle;

    private int search(int x, int y) {
        if (x >= n) {
            return 0;
        }

        if (minSum[x][y] != Integer.MAX_VALUE) {
            return minSum[x][y];
        }

        minSum[x][y] = Math.min(search(x + 1, y), search(x + 1, y + 1))
            + triangle.get(x).get(y);
        return minSum[x][y];
    }

    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        this.n = triangle.size();
        this.triangle = triangle;
        this.minSum = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minSum[i][j] = Integer.MAX_VALUE;
            }
        }

        return search(0, 0);
    }
} 


//Version 3 : (Time Limit Exceed) Up-Bottom Update
public class Solution {
    private int n;
    private int[][] minSum;
    private ArrayList<ArrayList<Integer>> triangle;

    private void search(int x, int y, int sum) {
        if (x >= n) {
            return;
        }
        if (sum + triangle.get(x).get(y) >= minSum[x][y]) {
            return;
        }
        minSum[x][y] = sum + triangle.get(x).get(y);

        search(x + 1, y, minSum[x][y]);
        search(x + 1, y + 1, minSum[x][y]);
    }

    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }

        this.n = triangle.size();
        this.triangle = triangle;
        this.minSum = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minSum[i][j] = Integer.MAX_VALUE;
            }
        }

        search(0, 0, 0);

        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            answer = Math.min(answer, minSum[n-1][i]);
        }
        return answer;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}