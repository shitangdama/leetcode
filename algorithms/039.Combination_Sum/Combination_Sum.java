public class Solution {
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> list = new ArrayList<Integer>();
		
        Arrays.sort(candidates);
		combinationSumRecur(candidates,0, target, list, res);
		//System.out.println(res.size());
		//System.out.println(res);
		return res;
    }
	
	public  static void combinationSumRecur(int candidates[],int k,int target,List<Integer> list,List<List<Integer>> res){
		if(target < 0 || k >= candidates.length) return;
		if(0 == target){
			res.add(new ArrayList<>(list));
			return;
		}
		list.add(candidates[k]);
		combinationSumRecur(candidates, k, target-candidates[k], list, res);
		list.remove(list.size()-1);
		while(  k+1 < candidates.length && candidates[k] == candidates[k+1]) k++;
		combinationSumRecur(candidates, k+1,  target, list, res);
	}
}
