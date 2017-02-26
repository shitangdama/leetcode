public class Solution {
	public List<Integer> twoSum(int[] numbers, int target) {
		List<Integer> ans = new ArrayList<>();
		int left = 1;
		int right = numbers.length;
		long tmpSum = 0;

		while (left < right) {
			tmpSum = numbers[left - 1] + numbers[right - 1];
			if (tmpSum == target) {
				ans.add(left);
				ans.add(right);
				return ans;
			} else if (tmpSum > target) {
				right--;
			} else {
				left++;
			}
		}
		return ans;
	}
}