public class Solution {
  public List<List<Integer>> combinationSum3(int k, int n) {
    List<List<Integer>> ans = new ArrayList<>();
    if (k == 0) {
      return ans;
    }

    dfsHelper(k, n, 1, 0, new ArrayList<>(), ans);
    return ans;
  }

  private void dfsHelper(int k, int n, int pos, int sum, List<Integer> taken, List<List<Integer>> ans) {
    if (taken.size() == k || sum > n) {
      if (sum == n) {
        ans.add(new ArrayList<>(taken));
      }
      return ;
    }

    for (int i = pos; i <= 9; i++) {
      sum += i;
      taken.add(i);
      dfsHelper(k, n, i + 1, sum, taken, ans);
      taken.remove(taken.size() - 1);
      sum -= i;
    }
  }
}