
public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> rst = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> solution = new ArrayList<Integer>();
        
        helper(rst, solution, n, k, 1);
        return rst;
    }
    
    private void helper(
        ArrayList<ArrayList<Integer>> rst, 
        ArrayList<Integer> solution, 
        int n, 
        int k, 
        int start) {

        if (solution.size() == k){
            rst.add(new ArrayList(solution));
            return;
        }
        
        for(int i = start; i<= n; i++){
            solution.add(i);
            
            // the new start should be after the next number after i
            helper(rst, solution, n, k, i+1); 
            solution.remove(solution.size() - 1);
        }
    }
}