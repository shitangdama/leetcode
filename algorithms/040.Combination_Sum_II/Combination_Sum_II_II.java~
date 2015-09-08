
public class Solution {

    private ArrayList<ArrayList<Integer>> results;

    public ArrayList<ArrayList<Integer>> combinationSum2(int[] candidates,
            int target) {
        if (candidates.length < 1) {
            return results;
        }

        ArrayList<Integer> path = new ArrayList<Integer>();
        java.util.Arrays.sort(candidates);
        results = new ArrayList<ArrayList<Integer>> ();
        combinationSumHelper(path, candidates, target, 0);

        return results;
    }

    private void combinationSumHelper(ArrayList<Integer> path, int[] candidates, int sum, int pos) {
        if (sum == 0) {
            results.add(new ArrayList<Integer>(path));
        }

        if (pos >= candidates.length || sum < 0) {
            return;
        }

        int prev = -1;
        for (int i = pos; i < candidates.length; i++) {
            if (candidates[i] != prev) {
                path.add(candidates[i]);
                combinationSumHelper(path, candidates, sum - candidates[i], i + 1);
                prev = candidates[i];
                path.remove(path.size()-1);
            }
        }
    }

}
