
public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
         ArrayList<ArrayList<Integer>> rst = new ArrayList<ArrayList<Integer>>();
         if (num == null || num.length == 0) {
             return rst; 
         }

         ArrayList<Integer> list = new ArrayList<Integer>();
         helper(rst, list, num);
         return rst;
    }
    
    public void helper(ArrayList<ArrayList<Integer>> rst, ArrayList<Integer> list, int[] num){
        if(list.size() == num.length) {
            rst.add(new ArrayList<Integer>(list));
            return;
        }
        
        for(int i = 0; i<num.length; i++){
            if(list.contains(num[i])){
                continue;
            }
            list.add(num[i]);
            helper(rst, list, num);
            list.remove(list.size() - 1);
        }
        
    }
}