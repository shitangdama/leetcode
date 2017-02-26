<<<<<<< HEAD
public class MissingRanges {
	public List<String> findMissingRanges(int[] nums, int lower, int upper) {
		List<String> ranges = new ArrayList<String>();
		if (nums == null) {
			return ranges;
		}

		int prev = -1;
		int cur = 0;
		for (int i = 0; i <= nums.length; i++) {
			prev = i > 0 ? nums[i - 1] : lower - 1;
			cur = i < nums.length ? nums[i] : upper + 1;
			if (cur - prev >= 2) {
				ranges.add(makeRange(prev + 1, cur - 1));
			}
		}

		return ranges;
	}

	private String makeRange(int start, int end) {
		return start < end ? start + "->" + end : "" + start;
	}
=======
public class MissingRanges {
	public List<String> findMissingRanges(int[] nums, int lower, int upper) {
		List<String> ranges = new ArrayList<String>();
		if (nums == null) {
			return ranges;
		}

		int prev = -1;
		int cur = 0;
		for (int i = 0; i <= nums.length; i++) {
			prev = i > 0 ? nums[i - 1] : lower - 1;
			cur = i < nums.length ? nums[i] : upper + 1;
			if (cur - prev >= 2) {
				ranges.add(makeRange(prev + 1, cur - 1));
			}
		}

		return ranges;
	}

	private String makeRange(int start, int end) {
		return start < end ? start + "->" + end : "" + start;
	}
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}